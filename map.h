#pragma once
#include <vector>
#include "game.h"

class map
{
public:

	void load_map();

private:

	//holds tiles from map
	std::vector<std::vector<tile>> data;

};
