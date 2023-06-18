#pragma once
#include "Command.h"
class CommandAttackByName : public Command
{
	char username[MAX_USERNAME_SIZE + 1];
	char attackingHeroName[MAX_USERNAME_SIZE + 1];
	char opponentHeroName[MAX_USERNAME_SIZE + 1];
public:
	CommandAttackByName(const char* username, const char* attackingHeroName, const char* opponentHeroName);
	CommandAttackByName(const CommandAttackByName& other) = delete;
	CommandAttackByName& operator=(const CommandAttackByName& other) = delete;
	void execute(GameSystem& system) override;
};

