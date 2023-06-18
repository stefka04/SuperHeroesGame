#include "GameSystem.h"
#include <exception>
#include <fstream>
#include <iostream>
#include <stdlib.h> 
#include <ctime>
GameSystem* GameSystem::instance = nullptr;
GameSystem::GameSystem()
{
	capacity = INIT_CAPACITY;
	users = new User * [capacity];
	market = new Marketplace();
	std::ifstream ifs(marketFile);
	if (!ifs.is_open())
	{
		throw std::exception("File can not be open!");
	}
	market->readFromFile(ifs);
	ifs.close();

	std::ifstream in(usersFile);

	if (!in.is_open())
	{
		throw std::exception("File can not be open!");
	}

	users[0] = new Administrator("mainadmin", "-", "-", "-", "MainAdmin0");
	if (market->getCountOfHeroes() == 0)
	{
		addSuperHeroToTheMarket(SuperHero("Water", "Girl", "Dolphin", 1200, StrengthTypes::Water, 2000));
		addSuperHeroToTheMarket(SuperHero("Fire", "Boy", "Firestorm", 1800, StrengthTypes::Fire, 3600));
		addSuperHeroToTheMarket(SuperHero("Peter", "Parker", "Spiderman", 3600, StrengthTypes::Earth, 5000));
	}
	
	readUsersFromFile(in);
	if (countOfUsers == 0)
	{
		countOfUsers = 1;
	}
	in.close();

}

GameSystem* GameSystem::getInstance()
{
	if (instance == nullptr)
	{
		instance = new GameSystem();
	}

	return instance;
}

void GameSystem::freeInstance()
{
	delete instance;
	instance = nullptr;
}
void GameSystem::freeUsers()
{
	for (size_t i = 0; i < countOfUsers; i++)
	{
		delete users[i];
	}
	delete[] users;
	capacity = countOfUsers = 0;
}
void GameSystem::resizeUsers()
{
	User** resized = new User * [capacity *= 2];
	for (size_t i = 0; i < countOfUsers; i++)
	{
		resized[i] = users[i];
	}
	delete[] users;
	users = resized;
}

GameSystem::~GameSystem()
{
	delete market; 
	market = nullptr;
	freeUsers();
	freeInstance();
}
bool GameSystem::checkIfUserLoggedBefore(size_t index) const
{
	size_t countOfLogged = loggedIndexes.getSize();
	for (size_t i = 0; i < countOfLogged; i++)
	{
		if (loggedIndexes[i] == index)
		{
			return true;
		}
	}
	return false;
}
void GameSystem::periodEnd()                 
{
	size_t countOfLogged = loggedIndexes.getSize();
	for (size_t i = 0; i < countOfLogged; i++)
	{
		long increasedMoney = dynamic_cast <Player*>(users[loggedIndexes[i]])->getMoney() + NEW_PERIOD_MONEY;
		dynamic_cast <Player*>(users[loggedIndexes[i]])->setMoney(increasedMoney);
	}
	loggedIndexes.clear();
}
void GameSystem::setIndexOfCurrentUser(const char* username, const MyString& password)
{
	size_t index = getIndexOfUserByUsername(username);
	if (users[index]->getPassword() == password)
	{
		indexOfCurrentUser = index;
		if (users[indexOfCurrentUser]->getUserType() == UserType::Player)
		{
			if (checkIfUserLoggedBefore(indexOfCurrentUser))
			{
				periodEnd();
			}
			loggedIndexes.pushBack(indexOfCurrentUser);
		}
		return;
	}
	throw std::invalid_argument("Invalid password!");
}

void GameSystem::readUsersFromFile(std::ifstream& in)
{
	size_t count = 0; 
	in >> count;
	in.ignore();
	MyString typeOfUser;
	for (size_t i = 0; i < count; i++)
	{
		in >> typeOfUser;
		if (typeOfUser == "Player")
		{
			Player* player = new Player();
			player->readFromFile(in);
			addUser(player);
		}
		else
		{
			Administrator* administrator = new Administrator();
			administrator->readFromFile(in);
			addUser(administrator);
		}
	}
}

void GameSystem::saveToFile(std::ofstream& out)
{
	std::ofstream outPlayers(leaderboardFile);
	if (!outPlayers.is_open())
	{
		throw std::exception("File can not be open!");
	}
	out << countOfUsers << std::endl;
	for (size_t i = 0; i < countOfUsers; i++)
	{
		users[i]->writeToFile(out);
		if (i + 1 != countOfUsers)
		{
			out << std::endl;
		}
		if (users[i]->getUserType() == UserType::Player)
		{
			outPlayers << users[i]->getUsername() << "," << dynamic_cast <Player*>(users[i])->getMoney() << "$" << std::endl; 
		}
	}
	outPlayers.close();
	std::ofstream outMarket(marketFile);
	if (!outMarket.is_open())
	{
		throw std::exception("File can not be open!");
	}
	market->writeToFile(outMarket);
	outMarket.close();
}

size_t GameSystem::getIndexOfCurrentUser() const
{
	return indexOfCurrentUser;
}
size_t GameSystem::getIndexOfUserByUsername(const char* username) const
{
	for (size_t i = 1; i < countOfUsers; i++)                
	{
		if (strcmp(users[i]->getUsername(), username) == 0)
		{
			return i;
		}
	}
	throw std::invalid_argument("Not excisting user!");
}
const User& GameSystem:: getUserAtIndex(int index) const
{
	if (index < 0 || index >= countOfUsers)
	{
		throw std::invalid_argument("Not excisting user!");
	}
	return *users[index];
}
bool GameSystem::checkIsUsernameTaken(const char* username) const
{
	try
	{
		getIndexOfUserByUsername(username);
		return true;
	}
	catch (std::invalid_argument)
	{
		return false;
	}
}
void GameSystem::addUser(User* newUser)
{
	if (users[indexOfCurrentUser]->getUserType() == UserType::Player)
	{
		throw std::exception("Error! Only administrators can add new users!");
	}
	if (countOfUsers == capacity)
	{
		resizeUsers();
	}
	if (!checkIsUsernameTaken(newUser->getUsername()))
	{
		users[countOfUsers++] = newUser;
	}
	else
	{
		std::cout << "Cannot add a user with already used name by another user!";
	}
}
void GameSystem::addPlayer(const char* username, const MyString& firstName, const MyString& secondName,
	const MyString& email, const MyString& password)
{
	Player* newPlayer = new Player(username, firstName, secondName, email, password);
	newPlayer->setMoney(SEED_MONEY);
	addUser(newPlayer);
}
void GameSystem::addAdministrator(const char* username, const MyString& firstName, const MyString& secondName,
	const MyString& email, const MyString& password)
{
	Administrator* newAdmin = new Administrator(username, firstName, secondName, email, password);
	addUser(newAdmin);
}
size_t GameSystem::getCountOfPlayersLogged() const
{
	return loggedIndexes.getSize();
}

void GameSystem::deleteUser(const char* username)
{
	size_t index = getIndexOfUserByUsername(username);
	if (users[index]->getUserType() == UserType::Administrator)
	{
		throw std::exception("Cannot delete an administrator!");
	}
	else if (users[indexOfCurrentUser]->getUserType() == UserType::Player)
	{
		if (strcmp(users[indexOfCurrentUser]->getUsername(), username) != 0)
		{
			throw std::exception("Cannot delete other players!");
		}
	}
	users[index] = users[--countOfUsers];
}

void GameSystem::showPlayers() const
{

	for (size_t i = 0; i < countOfUsers; i++)
	{
		if (users[i]->getUserType() == UserType::Player)                            
		{
			if (users[indexOfCurrentUser]->getUserType() == UserType::Player)
			{
				std::cout << "Username: " << users[i]->getUsername() << std::endl
					<< "Money: " << dynamic_cast <Player*>(users[i])->getMoney() << "$" << std::endl;  
				dynamic_cast <Player*>(users[i])->printShortInfoForSuperHeroes();
			}
			else
			{
				std::cout << "Username: " << users[i]->getUsername() << std::endl
					<< "FirstName: " << users[i]->getFirstName() << std::endl
					<< "SecondName: " << users[i]->getSecondName() << std::endl
					<< "Email: " << users[i]->getEmail() << std::endl
					<< "Money: " << dynamic_cast <Player*>(users[i])->getMoney() << "$" << std::endl; 
				dynamic_cast <Player*>(users[i])->printSuperHeroes();
			}
			std::cout << std::endl;
		}
	}
}
void GameSystem::showAdministrators() const
{
	if (users[indexOfCurrentUser]->getUserType() == UserType::Player)
	{
		return;
	}
	for (size_t i = 0; i < countOfUsers; i++)
	{
		if (users[i]->getUserType() == UserType::Administrator)
		{
			std::cout << "Username: " << users[i]->getUsername() << std::endl
				<< "FirstName: " << users[i]->getFirstName() << std::endl
				<< "SecondName: " << users[i]->getSecondName() << std::endl
				<< "Email: " << users[i]->getEmail() << std::endl;
			std::cout << std::endl;
		}
	}
}
template <typename T>
void GameSystem::swap(T& item1, T& item2)
{
	T temp = std::move(item1);
	item1 = std::move(item2);
	item2 = std::move(temp);
}
void GameSystem::sortByMoney(MyVector<MyString>& usernames, MyVector<long>& moneyArr)
{
	size_t countOfPlayers = usernames.getSize();
	for (size_t i = 0; i < countOfPlayers - 1; i++)
	{
		bool hasSwaps = false;
		for (size_t j = 0; j < countOfPlayers - 1 - i; j++)
		{
			if (moneyArr[j] < moneyArr[j + 1])
			{
				swap(moneyArr[j], moneyArr[j + 1]);
				swap(usernames[j], usernames[j + 1]);
				hasSwaps = true;
			}
		}
		if (!hasSwaps)
		{
			break;
		}
	}
}
void GameSystem::readLeaderBoardFile(MyVector<MyString>& usernames, MyVector<long>& moneyArr) const
{
	std::ifstream in(leaderboardFile);
	if (!in.is_open())
	{
		std::cout << "File can not be open!";
		return;
	}
	char buff[MAX_BUFF_SIZE];
	while (!in.eof())
	{
		in.getline(buff, MAX_BUFF_SIZE, ',');
		if (strcmp(buff, "") == 0)
		{
			return;
		}
		usernames.pushBack(buff);
		long money;
		in >> money;
		moneyArr.pushBack(money);
		in.ignore(2); 
	}
	in.close();
}
void GameSystem::showLeaderBoard() const
{
	MyVector<MyString> usernames;
	MyVector<long> moneyArr;
	readLeaderBoardFile(usernames, moneyArr);
	size_t countOfPlayers = usernames.getSize();
	sortByMoney(usernames, moneyArr);
	for (size_t i = 0; i < countOfPlayers; i++)
	{
		std::cout << i + 1 << ". " << usernames[i] << "  " << moneyArr[i] << "$" << std::endl;
	}
	std::cout << std::endl;
}

void GameSystem::showMarket() const
{
	market->print();
}

void GameSystem::showBalance() const
{
	if (users[indexOfCurrentUser]->getUserType() == UserType::Administrator)
	{
		throw std::exception("Error! Admins have not balance to show!");
	}
	dynamic_cast<Player*>(users[indexOfCurrentUser])->showBalance();
}
bool GameSystem::checkIsSuperHeroTaken(const char* supername) const 
{
	for (size_t i = 1; i < countOfUsers; i++)
	{
		if (users[i]->getUserType() == UserType::Player)
		{
			try
			{
				dynamic_cast<Player*>(users[i])->getIndexOfHeroByName(supername);
				return true; 
			}
			catch(std::invalid_argument)
			{
				continue;
			}
		}
	}
	return false;
}

void GameSystem:: buySuperHero(const char* supername)
{
	if (users[indexOfCurrentUser]->getUserType() == UserType::Administrator)
	{
		throw std::exception("Error! Admins can not buy superheroes!");
	}
	
	try
	{
		size_t index = dynamic_cast<Player*>(users[indexOfCurrentUser])->getIndexOfHeroByName(supername);
		throw std::exception("Error! Duplication of the same superhero is not allowed!");
	}
	catch (std::invalid_argument)
	{
		if (checkIsSuperHeroTaken(supername))
		{
			throw std::exception("Error! Duplication of the same superhero is not allowed!");
		}
		else
		{
			size_t index = market->getIndexOfHeroByName(supername);
			long money = dynamic_cast<Player*>(users[indexOfCurrentUser])->getMoney();
			long price = market->getSuperHeroAtIndex(index).getPrice();
			if (money < price)
			{
				std::cout << "There is not enought money! You have : " << money << "$ " << supername << " costs: " << price << "$ ";
				return;
			}
			dynamic_cast<Player*>(users[indexOfCurrentUser])->addSuperHero(market->getSuperHeroAtIndex(index));
			dynamic_cast<Player*>(users[indexOfCurrentUser])->setMoney(money - price);
			market->removeSuperHero(supername);       
		}
	}
}
void GameSystem::addSuperHeroToTheMarket(const SuperHero& newHeroe)
{
	if (users[indexOfCurrentUser]->getUserType() == UserType::Player)
	{
		throw std::exception("Error! Players can not add superheroes to the market!");
	}
    market->addSuperHero(newHeroe);
}
void GameSystem::addAlreadyBoughtHeroToTheMarket(const char* supername)
{
	for (size_t i = 0; i < countOfUsers; i++)
	{
		if (users[i]->getUserType() == UserType::Player && dynamic_cast<Player*>(users[i])->haveSuperHero(supername))
		{
			size_t indexOfHero = dynamic_cast<Player*>(users[i])->getIndexOfHeroByName(supername);
			addSuperHeroToTheMarket(dynamic_cast<Player*>(users[i])->getSuperHeroAtIndex(indexOfHero));
			return;
		}
	}
}
void GameSystem::attack(const char* opponentUsername, const char* attackingHeroName, const char* opponentHeroName)
{
	if (users[indexOfCurrentUser]->getUserType() == UserType::Administrator)
	{
		throw std::logic_error("Only players can attack other players!");
	}
	size_t indexOfOpponent = getIndexOfUserByUsername(opponentUsername);
	if (users[indexOfOpponent]->getUserType() == UserType::Administrator)
	{
		std::cout << "Error! Can not attack admins, only other players!";
		return;
	}
	Player* opponent = dynamic_cast<Player*>(users[indexOfOpponent]);            
	dynamic_cast<Player*>(users[indexOfCurrentUser])->attack(*opponent, attackingHeroName, opponentHeroName);
}
void GameSystem::attack(const char* attackingHeroName)
{
	srand(time(0));  //Use current time as seed for random generator
	size_t indexOfOpponent = 0, indexOfHero = 0;
	do
	{
		indexOfOpponent = rand() % countOfUsers;
	} while (users[indexOfOpponent]->getUserType() != UserType::Administrator);
	size_t countOfHeroes = dynamic_cast<Player*>(users[indexOfCurrentUser])->getCountOfSuperHeroes();

	indexOfHero = rand() % countOfHeroes;

	attack(users[indexOfOpponent]->getUsername(), attackingHeroName, dynamic_cast<Player*>(users[indexOfOpponent])->getSuperHeroAtIndex(indexOfHero).getSupername());
}
void GameSystem::changeAttackingMode(const char* superHeroName, AttackingMode mode)
{
	if (users[indexOfCurrentUser]->getUserType() == UserType::Administrator)
	{
		throw std::exception("Error! Administrator can not set attacking mode of superhero!");
	}
	dynamic_cast<Player*>(users[indexOfCurrentUser])->changeAttackPossition(superHeroName, mode);
}
void GameSystem::logOut()
{
	std::ofstream out(usersFile);
	if (!out.is_open())
	{
		std::cout << "File can not be open!";
		return;
	}
	indexOfCurrentUser = 0;
	saveToFile(out);
}