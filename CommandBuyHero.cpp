#include "CommandBuyHero.h"
#pragma warning (disable:4996)
#include <exception>
CommandBuyHero::CommandBuyHero(const char* username)
{
	strcpy(this->username, username);
}

void CommandBuyHero::execute(GameSystem& system)
{
	try {
		system.getInstance()->buySuperHero(username);
		std::cout << username << ",  bought it successfully!" << std::endl;
	}
	catch (std::logic_error)
	{
		
	}
	catch (std::exception)
	{
		std::cout << "Error! Duplication of the same superhero is not allowed!";
	}
}
