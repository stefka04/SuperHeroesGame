#include "CommandDeleteProfile.h"
#pragma warning (disable:4996)
#include <exception>
CommandDeleteProfile::CommandDeleteProfile(const char* username)
{
	strcpy(this->username, username);
}

void CommandDeleteProfile::execute(GameSystem& system)
{
	try
	{
		system.getInstance()->deleteUser(username);
		std::cout << "Player deleted successfully!" << std::endl;
	}
	catch (std::exception)
	{
		std::cout << "You can not delete this profile!" << std::endl;
	}
}
