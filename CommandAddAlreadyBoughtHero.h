#pragma once
#include "Command.h"
class CommandAddAlreadyBoughtHero : public Command
{
	char supername[MAX_USERNAME_SIZE + 1];
public:
	CommandAddAlreadyBoughtHero(const char* username);
	CommandAddAlreadyBoughtHero(const CommandAddAlreadyBoughtHero& other) = delete;
	CommandAddAlreadyBoughtHero& operator=(const CommandAddAlreadyBoughtHero& other) = delete;
	void execute(GameSystem& system) override;
};

