#pragma once
#include "GameSystem.h"
class Command
{
public:
	virtual ~Command() = default;
	virtual void execute(GameSystem& system) = 0;
};

