#include "CommandAttackRandom.h"
#pragma warning (disable:4996)
CommandAttackRandom::CommandAttackRandom(const char* opponentUsername, const char* attackingHeroName)
{
	strcpy(this->opponentUsername, opponentUsername);
	strcpy(this->attackingHeroName, attackingHeroName);
}

void CommandAttackRandom::execute(GameSystem& system)
{
	try
	{
		system.getInstance()->attack(opponentUsername, attackingHeroName);
	}
	catch(std::logic_error)
	{
		std::cout << " Error!" << std:: endl;
	}
}
