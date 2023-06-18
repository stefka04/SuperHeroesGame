#pragma once
#include "Command.h"
class CommandDeleteProfile : public Command
{
	char username[MAX_USERNAME_SIZE];

public:
	CommandDeleteProfile(const char* username);
	CommandDeleteProfile(const CommandDeleteProfile& other) = delete;
	CommandDeleteProfile& operator=(const CommandDeleteProfile& other) = delete;
	void execute(GameSystem& system) override;
};

