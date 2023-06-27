#include "System.h"
#include <iostream>
#include "CommandFactory.h"
#include "GameSystem.h"

GameSystem* gameSystem = GameSystem::getInstance();
void printInitialMenu()
{
	std::cout << ">sign in" << std::endl;
	std::cout << ">add administrator" << std::endl;
	std::cout << ">add player" << std::endl;
}
void printPlayerMenu()
{
	std::cout << ">show balance" << std::endl;
	std::cout << ">show market" << std::endl;
	std::cout << ">show players" << std::endl;
	std::cout << ">show leaderboard" << std::endl;
	std::cout << ">delete profile" << std::endl;
	std::cout << ">buy" << std::endl;
	std::cout << ">set to defence" << std::endl;
	std::cout << ">set to attacking" << std::endl;
	std::cout << ">attack" << std::endl;
	std::cout << ">log out" << std::endl;
}
void printAdministratorMenu()
{
	std::cout << ">add player" << std::endl;
	std::cout << ">add administrator" << std::endl;
	std::cout << ">show players" << std::endl;
	std::cout << ">show market" << std::endl;
	std::cout << ">show leaderboard" << std::endl;
	std::cout << ">show administrators" << std::endl;
	std::cout << ">add new hero" << std::endl;
	std::cout << ">delete player" << std::endl;
	std::cout << ">log out" << std::endl;
}
void printMenu()
{
	if (gameSystem->getInstance()->getIndexOfCurrentUser() == 0)     
	{
		printInitialMenu();
		return;
	}
	gameSystem->getInstance()->getUserAtIndex(gameSystem->getInstance()->getIndexOfCurrentUser()).getUserType() == UserType::Player
		? printPlayerMenu() : printAdministratorMenu();
}

void commandExecutor() 
{
	while (true)
	{
		printMenu();
		try
		{
			CommandFactory::getInstance().getCommand()->execute(*gameSystem);
		}
		catch (std::exception e)
		{
			std::cout << e.what() << std::endl;
		}
	}
};



