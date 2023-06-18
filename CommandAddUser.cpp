#include "CommandAddUser.h"
#pragma warning(disable: 4996)
CommandAddUser::CommandAddUser(const char* username, const MyString& firstName, const MyString& secondName, const MyString& email, const MyString& password, UserType type)
{
	strcpy(this->username, username); 
	this->firstName = firstName;
	this->secondName = secondName;
	this->password = password;
	this->email = email;
	this->type = type;
}

void CommandAddUser::execute(GameSystem& system)
{
	type == UserType::Player ? system.getInstance()->addPlayer(username, firstName, secondName, email, password)
		: system.getInstance()->addAdministrator(username, firstName, secondName, email, password);
	
	
	switch (type)
	{
	case UserType::Administrator: std::cout << "Administrator "; break;
	case UserType::Player: std::cout << "Player "; break;
	}
	std::cout << username << "  created successfully! " << std::endl;
}
