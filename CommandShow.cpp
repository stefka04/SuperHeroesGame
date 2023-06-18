#include "CommandShow.h"
#include "Player.h"
CommandShow::CommandShow(const MyString& command)
{
	this->command = command;
}

void CommandShow::execute(GameSystem& system)
{
	if(command == "show balance")
	{
	system.getInstance()->showBalance();
	}
	else if(command == "show market")
	{
		system.getInstance()->showMarket(); 
	}
	else if (command == "show players")
	{
		system.getInstance()->showPlayers();
	}
	else if (command == "show administrators")
	{
		system.getInstance()->showAdministrators();
	}
	else if (command == "show leaderboard")
	{
		system.getInstance()->showLeaderBoard(); 
	}
	else
	{
		std::cout << "Not valid command!";
	}
}
