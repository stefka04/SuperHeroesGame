#include "CommandAddHero.h"
#pragma warning (disable:4996)
CommandAddHero::CommandAddHero(const MyString& firstName, const MyString& secondName, const char* supername, long price,
	StrengthTypes strengthType, unsigned strengthPoints)
{
	this->strengthType = strengthType;
	this->strengthPoints = strengthPoints;
	this->price = price;
	this->firstName = firstName;
	this->secondName = secondName;
	strcpy(this->supername, supername);
}

void CommandAddHero::execute(GameSystem& system)
{

	system.getInstance()->addSuperHeroToTheMarket(SuperHero(firstName, secondName, supername, price, strengthType, strengthPoints));
	std::cout << "Successfully add new hero to the market! " << std::endl;
}
