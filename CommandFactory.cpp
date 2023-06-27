#include "CommandFactory.h"
#include "CommandSignIn.h"
#include "CommandLogOut.h"
#include "CommandAddUser.h"
#include "CommandShow.h"
#include "CommandAddHero.h"
#include "CommandAddAlreadyBoughtHero.h"
#include "CommandAttackByName.h"
#include "CommandAttackRandom.h"
#include "CommandBuyHero.h"
#include "CommandDeleteProfile.h"
#include "CommandsetAttackingMode.h"
#include <exception>
static void inputUser(char* username, MyString& firstName, MyString& secondName,  MyString& email, MyString& password)
{
	std::cout << "Username:";
	std::cin >> username;
	std::cin.ignore(); 
	std::cout << "First name: ";
	std::cin >> firstName;
	std::cout << "Second name: ";
	std::cin >> secondName;
	std::cout << "Email:";
	std::cin >> email;
	std::cout << "Password:";
	std::cin >> password;
}

Command* addNewSuperHero()
{
	char username[MAX_USERNAME_SIZE + 1];
	MyString firstName;
	MyString secondName;
	long price = 0;
	unsigned strengthPoints = 0;
	MyString strengthType;
	StrengthTypes type = StrengthTypes::Earth;
	std::cout << "Username:";
	std::cin >> username;
	std::cin.ignore();
	std::cout << "First name: ";
	std::cin >> firstName;
	std::cout << "Second name: ";
	std::cin >> secondName;
	std::cout << "Strength points: ";
	std::cin >> strengthPoints;
	std::cout << "Price: ";
	std::cin >> price;
	std::cin.ignore();
	std::cout << "Strength Type: ";
	std::cin >> strengthType;
	if (strengthType == "Earth")
	{
		type = StrengthTypes::Earth;
	}
	else if (strengthType == "Fire")
	{
		type = StrengthTypes::Fire;
	}
	else if (strengthType == "Water")
	{
		type = StrengthTypes::Water;
	}
	return new CommandAddHero(firstName, secondName, username, price, type, strengthPoints);
}
Command* CommandFactory::getCommand() const
{
	std::cout << "Please enter command: ";
	MyString command;
	std::cin >> command;
	std::cout << std::endl;
	if (command == "sign in")
	{
		return signIn();
	}
	else if (command == "add player" || command == "add administrator")
	{
		return addUser(command);
	}
	
	else if (command == "add new hero")
	{
		return addHero();
	}
	else if (command == "show market" || command == "show leaderboard" || command == "show players" || command == "show administrators" 
		     || command == "show balance")
	{
		return new CommandShow(command);
	}
	else if (command == "delete profile" || command == "delete player")
	{
		return deleteUser();
	}
	else if (command == "buy")
	{
		return buy();
	}
	else if (command == "set to defence" || command == "set to attacking")
	{
		return changeAttackingMode(command);
	}
	else if (command == "attack")
	{
		return attack();
	}
	else if (command == "log out")
	{
		return new CommandLogOut();
	}
	else
	{
		std::cout << "Not valid command!";
		throw std::exception("Not valid command!");
	}
}
Command* CommandFactory::attack() const
{
	system("CLS");
	std::cout << ">attack user" << std::endl;
	std::cout << ">attack random hero" << std::endl;
	std::cout << "Please enter command: ";
	MyString command;
	std::cin >> command;
	std::cout << std::endl;


	if (command == "attack user")
	{
		char opponentHeroName[MAX_USERNAME_SIZE + 1];
		char attackingHeroName[MAX_USERNAME_SIZE + 1];
		char opponentUsername[MAX_USERNAME_SIZE + 1];
		std::cout << "Enter the user you want to attack: ";
		std::cin >> opponentUsername;
		std::cout << "Enter the superhero nickname you want to attack with: ";
		std::cin >> attackingHeroName;
		std::cout << "Enter the superhero you want to attack: ";
		std::cin >> opponentHeroName;
		std::cin.ignore();
		return new CommandAttackByName(opponentUsername, attackingHeroName, opponentHeroName);
	}
	else if (command == "attack random hero")
	{
		char opponentUsername[MAX_USERNAME_SIZE + 1];
		char attackingHeroName[MAX_USERNAME_SIZE + 1];
		std::cout << "Enter the superhero nickname you want to attack with: ";
		std::cin >> attackingHeroName;
		std::cout << "Enter the user you want to attack: ";
		std::cin >> opponentUsername;
		std::cin.ignore();
		return new CommandAttackRandom(opponentUsername, attackingHeroName);
	}
	else
	{
		throw std::exception("Not valid command!");
	}
}
Command* CommandFactory::changeAttackingMode(MyString& command) const
{
	char superHeroName[MAX_USERNAME_SIZE + 1];
	AttackingMode mode;
	std::cout << "Enter the superhero you want to set " << command << " ";
	std::cin >> superHeroName;
	std::cin.ignore();

	command == "set to defence" ? mode = AttackingMode::Defensive : mode = AttackingMode::Attacking;
	return new CommandSetAttackingMode(superHeroName, mode);
}
Command* CommandFactory::buy() const
{

	char superHeroName[MAX_USERNAME_SIZE + 1];
	std::cout << "Enter Superhero name from the market you wish to buy:";
	std::cin >> superHeroName;
	std::cin.ignore();
	return new CommandBuyHero(superHeroName);
}
Command* CommandFactory::deleteUser() const
{
	char username[MAX_USERNAME_SIZE + 1];
	std::cout << "Username:";
	std::cin >> username;
	std::cin.ignore();
	return new CommandDeleteProfile(username);
}
Command* CommandFactory::addHero() const
{
	system("CLS");
	std::cout << "add new hero" << std::endl;
	std::cout << "add already bought hero" << std::endl;
	std::cout << "Please enter command: ";
	MyString command;
	std::cin >> command;
	if (command == "add new hero")
	{
		return addNewSuperHero();
	}
	char username[MAX_USERNAME_SIZE + 1];
	std::cout << "Username:";
	std::cin >> username;
	std::cin.ignore();
	return new CommandAddAlreadyBoughtHero(username);
}
Command* CommandFactory::addUser(MyString& command) const
{
	char username[MAX_USERNAME_SIZE + 1];
	MyString firstName;
	MyString secondName;
	MyString email;
	MyString password;

	inputUser(username, firstName, secondName, email, password);
	return command == "add administrator" ? new CommandAddUser(username, firstName, secondName, email, password, UserType::Administrator)
		: new CommandAddUser(username, firstName, secondName, email, password, UserType::Player);
}
Command* CommandFactory::signIn() const
{
	char username[MAX_USERNAME_SIZE + 1];
	MyString password;
	std::cout << "Username:";
	std::cin >> username;
	std::cin.ignore();
	std::cout << "Password:";
	std::cin >> password;
	return new CommandSignIn(username, password);
}
CommandFactory& CommandFactory::getInstance()
{
	static CommandFactory factory;
	return factory;
}