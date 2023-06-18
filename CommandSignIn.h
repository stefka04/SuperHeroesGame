#pragma once
#include "Command.h"
class CommandSignIn : public Command
{
	char username[MAX_USERNAME_SIZE + 1];
	MyString password;

public:
	CommandSignIn(const char* username, const MyString& password);
	CommandSignIn(const CommandSignIn& other) = delete;
	CommandSignIn& operator=(const CommandSignIn& other) = delete;
	void execute(GameSystem& system) override;
};

