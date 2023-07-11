#pragma once
#include <vector>
#include <iostream>
#include "game.h"


class status
{
public:

	long gold_amount()
	{
		return gold;
	}

	void gold_change(int cost)
	{
		gold -= cost;
	}

	void push_unit(const unit& obj)
	{
		unit_info.push_back(obj);
	}

private:

	long gold = 2000;
	std::vector<unit> unit_info;

	friend std::ostream& operator << (std::ostream& os, const status& obj);
};
