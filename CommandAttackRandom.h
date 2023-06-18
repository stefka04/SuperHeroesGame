#pragma once
#include "Command.h"
class CommandAttackRandom : public Command
{
	char attackingHeroName[MAX_USERNAME_SIZE + 1];
public:
	CommandAttackRandom(const char* attackingHeroName);
	CommandAttackRandom(const CommandAttackRandom& other) = delete;
	CommandAttackRandom& operator=(const CommandAttackRandom& other) = delete;
	void execute(GameSystem& system) override;
};

