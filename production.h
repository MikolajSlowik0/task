#pragma once
#include "game.h"
#include "status.h"

class Production
{
public:

	void production(unit_type type, status& ob);
	

private:
	int unit_count = 0;

	std::pair<int, int> unit_charge(unit_type unit);
	
};
