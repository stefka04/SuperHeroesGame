#include "CommandSetAttackingMode.h"
#pragma warning (disable:4996)
CommandSetAttackingMode::CommandSetAttackingMode(const char* superHeroName, const AttackingMode& mode)
{
	strcpy(supername, superHeroName);
	this->mode = mode;
}

void CommandSetAttackingMode::execute(GameSystem& system)
{
	try
	{
		system.getInstance()->changeAttackingMode(supername, mode);
		mode == AttackingMode::Defensive ? std::cout << supername << " set to defense" << " successfully!" << std::endl
			: std::cout << supername << " set to attacking " << "successfully!" << std::endl;
		std::cout << std::endl;
	}
	catch (std::logic_error)
	{
		std::cout << " Error!";
	}
   
}
