#include "CommandAddAlreadyBoughtHero.h"
#pragma warning (disable:4996)
CommandAddAlreadyBoughtHero::CommandAddAlreadyBoughtHero(const char* username)
{
	strcpy(supername, username);
}

void CommandAddAlreadyBoughtHero::execute(GameSystem& system)
{
	system.addAlreadyBoughtHeroToTheMarket(supername);
}
