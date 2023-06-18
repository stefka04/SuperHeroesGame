#pragma once
#include "Command.h"
class CommandFactory
{
	CommandFactory() = default;
	CommandFactory(const CommandFactory&) = delete;
	CommandFactory& operator=(const CommandFactory&) = delete;

	Command* attack() const;
	Command* changeAttackingMode(MyString& command) const;
	Command* buy() const;
	Command* deleteUser() const;
	Command* addHero() const;
	Command* addUser(MyString& command) const;
	Command* signIn() const;
public:
	Command* getCommand() const;
	static CommandFactory& getInstance();
};

