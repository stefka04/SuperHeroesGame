#pragma once
#include "Command.h"
class CommandAddUser : public Command
{
	char username[MAX_USERNAME_SIZE + 1];
	MyString firstName;
	MyString secondName;
	MyString email;
	MyString password;
	UserType type;
public:
	CommandAddUser(const char* username, const MyString& firstName, const MyString& secondName,
		const MyString& email, const MyString& password, UserType type);
	CommandAddUser(const CommandAddUser& other) = delete;
	CommandAddUser& operator=(const CommandAddUser& other) = delete;
	void execute(GameSystem& system) override;
};

