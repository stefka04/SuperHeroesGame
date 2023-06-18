#include "CommandSignIn.h"
#pragma warning(disable:4996)
CommandSignIn::CommandSignIn(const char* username, const MyString& password)
{
	strcpy(this->username, username);
	this->password = password;
}

void CommandSignIn::execute(GameSystem& system)
{
	try {
		system.setIndexOfCurrentUser(username, password);
		std::cout << username <<" you have successfully sign in as ";
		switch (system.getInstance()->getUserAtIndex(system.getInstance()->getIndexOfUserByUsername(username)).getUserType())
		{
		case UserType::Administrator: std::cout << "administrator" << std::endl; break;
		case UserType::Player: std::cout << "player" << std::endl; break;
		}
	}
	catch (std::invalid_argument)
	{
		std::cout << "Not valid profile!" << std::endl;
	}
}
