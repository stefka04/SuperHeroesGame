#pragma once
#include "Command.h"
class CommandSetAttackingMode : public Command
{
	char supername[MAX_USERNAME_SIZE + 1];
	AttackingMode mode;
public:
	CommandSetAttackingMode(const char* superHeroName, const AttackingMode& mode);
	CommandSetAttackingMode(const CommandSetAttackingMode& other) = delete;
	CommandSetAttackingMode& operator=(const CommandSetAttackingMode& other) = delete;
	void execute(GameSystem& system) override;
};

