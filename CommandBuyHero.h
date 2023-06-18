#pragma once
#include "Command.h"
class CommandBuyHero : public Command
{
	char username[MAX_USERNAME_SIZE + 1];
public:
	CommandBuyHero(const char* username);
	CommandBuyHero(const CommandBuyHero& other) = delete;
	CommandBuyHero& operator=(const CommandBuyHero& other) = delete;
	void execute(GameSystem& system) override;
};

