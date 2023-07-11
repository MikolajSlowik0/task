#pragma once
#include <vector>
#include <iostream>
#include "game.h"

class commands
{
public:

private:
	friend std::istream& operator >> (std::istream& os, commands& obj);
	std::vector<Command> command_queue;
};
