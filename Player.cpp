#include "Player.h"
#include "Constants.h"
#include <sstream>
#include <iostream>


Player::Player()
{
	type = UserType::Player;
	money = SEED_MONEY;
	countOfMoves = 0;
}

Player::Player(const char* username, const MyString& firstName, const MyString& secondName,
	const MyString& email, const MyString& password) : User(username, firstName, secondName, email, password, UserType::Player)
{
	money = SEED_MONEY;
	countOfMoves = 0;
}

User* Player::clone() const
{
	User* newObj = new Player(*this);
	return newObj;
}
long Player::getMoney() const
{
	return money;
}
void Player::setMoney(long money)
{
	if (money < 0)
	{
		money = 0;
		return;
	}
	this->money = money;
}
MyVector <SuperHero>& Player::getSuperHeroes()
{
	return superHeroes;
}
size_t Player::getCountOfSuperHeroes() const
{
	return superHeroes.getSize();
}
size_t Player::getIndexOfHeroByName(const char* superHeroeName) const
{
	size_t countOfSuperHeroes = superHeroes.getSize();
	for (size_t i = 0; i < countOfSuperHeroes; i++)
	{
		if (strcmp(superHeroes[i].getSupername(), superHeroeName) == 0)
		{
			return i;
		}
	}
	throw std::invalid_argument("Not excisting superHero!");
}
unsigned Player::getCountOfMoves() const
{
	return countOfMoves;
}
void Player::incrementCountOfMoves()
{
	if (!canMakeMove())
	{
		std::cout << firstName << " , you have reached your limit of operations for this round!" << std::endl;
		throw std::logic_error("Error");
	}
	countOfMoves++;
}
bool Player::canMakeMove() const
{
	return countOfMoves != MAX_MOVES;
}
const SuperHero& Player::getSuperHeroAtIndex(size_t index) const
{
	if (index >= superHeroes.getSize())
	{
		throw std::invalid_argument("Error! Not valid index!");
	}
	return superHeroes[index];
}
SuperHero& Player::getSuperHeroAtIndex(size_t index)
{
	if (index >= superHeroes.getSize())
	{
		throw std::invalid_argument("Error! Not valid index!");
	}
	return superHeroes[index];
}
bool Player::haveSuperHero(const char* superHeroName) const
{
	size_t count = superHeroes.getSize();
	for (size_t i = 0; i < count; i++)
	{
		try
		{
			getIndexOfHeroByName(superHeroName);
			return true;
		}
		catch (std::invalid_argument)
		{
			continue;
		}
	}
	return false;
}

void Player::showBalance() const
{
	std::cout << money << "$" << std::endl;
}
long Player::convertStringToNum(const char* str)
{
	long result = 0;
	size_t i = 0;
	while (str[i] != '\0')
	{
		result = (str[i++] - '0') + (result * 10);
	}
	return result;
}
void Player::compareHeroesByPoints(Player& opponent, size_t indexOfOpponentHero, MyVector<SuperHero>& superheroes, size_t indexOfAttackingHero)
{
	unsigned attackingHeroPoints = superHeroes[indexOfAttackingHero].getStrengthPoints();
	unsigned opponentHeroPoints = opponent.getSuperHeroAtIndex(indexOfOpponentHero).getStrengthPoints();
	if (attackingHeroPoints > opponentHeroPoints)
	{
		long difference = attackingHeroPoints - opponentHeroPoints;
		setMoney(getMoney() + difference);
		std::cout << " Congratulations you have won! You have earned " << difference << std::endl;
		opponent.setMoney(opponent.getMoney() - difference);
		opponent.getSuperHeroes().popAt(indexOfOpponentHero);
	}
	else if (attackingHeroPoints < opponentHeroPoints)
	{
		opponent.setMoney(opponent.getMoney() + z);
		long difference = opponentHeroPoints - attackingHeroPoints;
		setMoney(getMoney() - 2 * difference);
		std::cout << opponent.getUsername() << "has won!" << " You lost " << 2 * difference << "$" << std::endl;
		superHeroes.popAt(indexOfAttackingHero);
	}
}
void Player::readFromFile(std::ifstream& in)
{
	char buff[MAX_BUFF_SIZE];
	in.getline(username, MAX_USERNAME_SIZE, ',');
	in.getline(buff, MAX_BUFF_SIZE, ',');
	firstName = MyString(buff);
	in.getline(buff, MAX_BUFF_SIZE, ',');
	secondName = MyString(buff);
	in.getline(buff, MAX_BUFF_SIZE, ',');
	email = MyString(buff);
	in.getline(buff, MAX_BUFF_SIZE, ',');
	password = MyString(buff);
	in.getline(buff, MAX_BUFF_SIZE, ',');
	money = convertStringToNum(buff);
	in.getline(buff, MAX_BUFF_SIZE, ',');
	size_t size = convertStringToNum(buff);
	if (size == 0)
	{
		in.ignore();
	}
	for (size_t i = 0; i < size; i++)
	{
		SuperHero newHeroe;
		newHeroe.readFromFile(in);
		superHeroes.pushBack(newHeroe);
	}
}

void Player::changeAttackPossition(const char* superHeroName, const AttackingMode& mode)
{
	size_t index = getIndexOfHeroByName(superHeroName);
	incrementCountOfMoves();
	superHeroes[index].setAttackingMode(mode);
}
void Player::printSuperHeroes() const
{
	size_t size = superHeroes.getSize();
	for (size_t i = 0; i < size; i++)
	{
		superHeroes[i].printSuperHero();
	}
}

void Player::printShortInfoForSuperHeroes() const
{
	size_t size = superHeroes.getSize();
	for (size_t i = 0; i < size; i++)
	{
		std::cout << "  " << i + 1 << ".";
		superHeroes[i].printShortInfo();
	}
}

void Player::writeToFile(std::ofstream& out) const
{
	out << "Player" << std::endl;
	out << username << ",";
	out << firstName << ",";
	out << secondName << ",";
	out << email << ",";
	out << password << ",";
	out << money << ",";
	size_t size = superHeroes.getSize();
	out << size << ",";
	for (size_t i = 0; i < size; i++)
	{
		superHeroes[i].writeToFile(out);
		if (i + 1 < size)
		{
			out << std::endl;
		}
	}
}
void Player::addSuperHero(const SuperHero& newHeroe)
{
	incrementCountOfMoves();
	superHeroes.pushBack(newHeroe);
}

void Player::removeSuperHero(const char* nickname)
{
	size_t index = getIndexOfHeroByName(nickname);
	superHeroes.popAt(index);
}

void Player::attack(Player& opponent, const char* attackingHeroName, const char* opponentHeroName)
{
	incrementCountOfMoves();
	size_t indexOfAttackingHero = getIndexOfHeroByName(attackingHeroName);
	if (opponent.getCountOfSuperHeroes() == 0)
	{
		opponent.setMoney(opponent.getMoney() - superHeroes[indexOfAttackingHero].getStrengthPoints());
		setMoney(getMoney() + x);
		std::cout << " Congratulations you have won! You have earned " << x << "$!" << std::endl;
		return;
	}
	size_t indexOfOpponentHero = opponent.getIndexOfHeroByName(opponentHeroName);
	StrengthTypes attackingType = superHeroes[indexOfAttackingHero].getStrengthType();
	StrengthTypes opponentType = opponent.getSuperHeroAtIndex(indexOfOpponentHero).getStrengthType();
	if (attackingType != StrengthTypes::Fire && attackingType > opponentType
		|| (attackingType == StrengthTypes::Fire && opponentType == StrengthTypes::Earth))
	{
		superHeroes[indexOfAttackingHero].setStrengthPoints(superHeroes[indexOfAttackingHero].getStrengthPoints() * 2);
		if (opponent.getSuperHeroAtIndex(indexOfOpponentHero).getAttackingMode() == AttackingMode::Defensive)
		{
			opponent.getSuperHeroes().popAt(indexOfOpponentHero);
		}
	}
	else if (attackingType != opponentType)
	{
		opponent.getSuperHeroAtIndex(indexOfOpponentHero).setStrengthPoints(opponent.getSuperHeroAtIndex(indexOfOpponentHero)
			.getStrengthPoints() * 2);
		if (opponent.getSuperHeroAtIndex(indexOfOpponentHero).getAttackingMode() == AttackingMode::Defensive)
		{
			superHeroes.popAt(indexOfAttackingHero);
			return;
		}
	}
	if (opponent.getSuperHeroAtIndex(indexOfOpponentHero).getAttackingMode() == AttackingMode::Attacking)
	{
		compareHeroesByPoints(opponent, indexOfOpponentHero, superHeroes, indexOfAttackingHero);
	}
}