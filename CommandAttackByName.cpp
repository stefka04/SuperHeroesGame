#include "CommandAttackByName.h"
#pragma warning(disable:4996)
CommandAttackByName::CommandAttackByName(const char* username, const char* attackingHeroName, const char* opponentHeroName)
{
	strcpy(this->username, username);
	strcpy(this->attackingHeroName, attackingHeroName);
	strcpy(this->opponentHeroName, opponentHeroName);
}

void CommandAttackByName::execute(GameSystem& system)
{
	try
	{
		system.getInstance()->attack(username, attackingHeroName, opponentHeroName);
	}
	catch (std::logic_error)
	{
		std::cout << " Error!" << std::endl;
	}
}
