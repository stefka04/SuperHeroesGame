#pragma once
#include "Command.h"
class CommandLogOut : public Command
{

public:
	CommandLogOut() = default;  
	CommandLogOut(const CommandLogOut& other) = delete;
	CommandLogOut& operator=(const CommandLogOut& other) = delete;
	void execute(GameSystem& system) override;
};

