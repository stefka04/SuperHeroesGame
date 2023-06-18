#pragma once
#include "Command.h"
class CommandShow : public Command
{
	MyString command;
public:
	CommandShow(const MyString& numberOfCommand);
	CommandShow(const CommandShow& other) = delete;
	CommandShow& operator=(const CommandShow& other) = delete;
	void execute(GameSystem& system) override;

};

