#pragma once
#include "Command.h"
class CommandAddHero : public Command
{
	char supername[MAX_USERNAME_SIZE + 1];
	AttackingMode mode;
	StrengthTypes strengthType;
	unsigned strengthPoints;
	long price;
	MyString firstName;
	MyString secondName;
public:
	CommandAddHero(const MyString& firstName, const MyString& secondName, const char* supername, long price,
		StrengthTypes strengthType, unsigned strengthPoints);
	CommandAddHero(const CommandAddHero& other) = delete;
	CommandAddHero& operator=(const CommandAddHero& other) = delete;
	void execute(GameSystem& system) override;
};

