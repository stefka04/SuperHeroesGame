#include "CommandSignIn.h"
#pragma warning(disable:4996)
CommandSignIn::CommandSignIn(const char* username, const MyString& password)
{
	strcpy(this->username, username);
	this->password = password;
}

void CommandSignIn::execute(GameSystem& gameSystem)
{
	gameSystem.setIndexOfCurrentUser(username, password);
	system("CLS");
	std::cout << username << " you have successfully sign in as ";
	switch (gameSystem.getInstance()->getUserAtIndex(gameSystem.getInstance()->getIndexOfUserByUsername(username)).getUserType())
	{
	case UserType::Administrator: std::cout << "administrator" << std::endl; break;
	case UserType::Player: std::cout << "player" << std::endl; break;
	}
}
