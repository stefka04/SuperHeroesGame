#include "CommandAttackRandom.h"
#pragma warning (disable:4996)
CommandAttackRandom::CommandAttackRandom(const char* attackingHeroName)
{
	strcpy(this->attackingHeroName, attackingHeroName);
}

void CommandAttackRandom::execute(GameSystem& system)
{
	try
	{
		system.getInstance()->attack(attackingHeroName);
	}
	catch(std::logic_error)
	{
		std::cout << " Error!" << std:: endl;
	}
}
