#include "SuperHero.h"
#include <sstream>
#pragma warning(disable:4996)
#include <cstring>
long SuperHero::convertStringToNum(const char* str)
{
	long result = 0;
	size_t i = 0;
	while (str[i] != '\0')
	{
		result = (str[i++] - '0') + (result * 10);
	}
	return result;
}
SuperHero::SuperHero() : strengthType(StrengthTypes::Fire), strengthPoints(0), price(0), mode(AttackingMode::Defensive), supername("None"),
firstName("None"), secondName("None") {}

SuperHero::SuperHero(const MyString& firstName, const MyString& secondName, const char* supername, long price,
	StrengthTypes strengthType, unsigned strengthPoints) : mode(AttackingMode::Defensive) 
{
	this->strengthType = strengthType;
	this->strengthPoints = strengthPoints;
	this->price = price;
	this->firstName = firstName;
	this->secondName = secondName;
	strcpy(this->supername, supername);
}

void SuperHero::setAttackingMode(const AttackingMode& mode)
{
	this->mode = mode;
}
void SuperHero::setStrengthPoints(unsigned points)
{
	strengthPoints = points;
}
const char* SuperHero::getSupername() const
{
	return supername;
}

const AttackingMode& SuperHero::getAttackingMode() const
{
	return mode;
}

unsigned SuperHero::getStrengthPoints() const
{
	return strengthPoints;
}

long SuperHero::getPrice() const
{
	return price;
}

const MyString& SuperHero::getFirstName() const
{
	return firstName;
}

const MyString& SuperHero::getSecondName() const
{
	return secondName;
}

const StrengthTypes& SuperHero::getStrengthType() const
{
	return strengthType;
}

void SuperHero::writeToFile(std::ofstream& out) const
{
	out << supername << "," << firstName << ","
		<< secondName << "," << price
		<< "," << strengthPoints << ",";
	switch (mode)
	{
	case AttackingMode::Attacking: out << "Attacking"; break;
	case AttackingMode::Defensive: out << "Defensive"; break;
	}
	out << ",";

	switch (strengthType)
	{
	case StrengthTypes::Fire:  out << "Fire"; break;
	case StrengthTypes::Earth: out << "Earth"; break;
	case StrengthTypes::Water: out << "Water"; break;
	}
}
void SuperHero::readFromFile(std::ifstream& in)
{
	char buff[MAX_BUFF_SIZE];
	in.getline(buff, MAX_BUFF_SIZE);
	std::stringstream str(buff);
	str.getline(supername, MAX_USERNAME_SIZE, ',');
	str.getline(buff, MAX_BUFF_SIZE, ',');
	firstName = MyString(buff);
	str.getline(buff, MAX_BUFF_SIZE, ',');
	secondName = MyString(buff);
	str.getline(buff, MAX_BUFF_SIZE, ',');
	price = convertStringToNum(buff);
	str.getline(buff, MAX_BUFF_SIZE, ',');
	strengthPoints = convertStringToNum(buff);
	str.getline(buff, MAX_BUFF_SIZE, ',');
	mode = strcmp(buff, "Attacking") == 0 ? AttackingMode::Attacking : AttackingMode::Defensive;
	str.getline(buff, MAX_BUFF_SIZE, ',');
	if (strcmp(buff, "Fire") == 0)
	{
		strengthType = StrengthTypes::Fire;
	}
	else if (strcmp(buff, "Earth") == 0)
	{
		strengthType = StrengthTypes::Earth;
	}
	else
	{
		strengthType = StrengthTypes::Water;
	}
}

void SuperHero::printSuperHero() const
{
	std::cout << "Supername: " << getSupername() << " " << "Name: " << getFirstName() << " "
		<< getSecondName() << " " << "Price: " << getPrice()
		<< " Strength Points: " << getStrengthPoints() << " Attacking mode: ";
	switch (getAttackingMode())
	{
	case AttackingMode::Attacking: std::cout << "Attacking  "; break;
	case AttackingMode::Defensive: std::cout << "Defensive  "; break;
	}

	std::cout << "Strength Type: ";
	switch (getStrengthType())
	{
	case StrengthTypes::Fire:std::cout << "Fire"; break;
	case StrengthTypes::Earth:std::cout << "Earth"; break;
	case StrengthTypes::Water:std::cout << "Water"; break;
	}
	std::cout << std::endl;
}
void SuperHero::printShortInfo() const
{
	std::cout << "Username: " << getSupername() << "  ";

	switch (getStrengthType())
	{
	case StrengthTypes::Fire:std::cout << "Fire"; break;
	case StrengthTypes::Earth:std::cout << "Earth"; break;
	case StrengthTypes::Water:std::cout << "Water"; break;
	}
	std::cout << std::endl;
}