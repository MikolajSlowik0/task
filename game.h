#pragma once
#include <vector>
#include <string>

constexpr int max_turn = 2000;
constexpr int width = 32;
constexpr int height = 32;

enum class tile
{
	road = 0,
	obstacle = 9,
	base_blue = 1,
	base_red = 2,
	mine = 6
};

enum class unit_type
{
	Knight = 'K',
	Swordsman = 'S',
	Archer = 'A',
	Pikeman = 'P',
	Ram = 'R',
	Catapult = 'C',
	Worker = 'W',
	Base = 'B',
	Null_production = 0
};

enum class actions
{
	move = 'M',
	attack = 'A',
	build = 'B',
};

struct unit
{
	bool team;
	unit_type type;
	int ID;
	int cords_X;
	int cords_Y;
	int health;
	int speed;
	int range;
	unit_type production;
};

struct Command
{
	actions type;

	union
	{
		struct
		{
			int X;
			int Y;
		} move;

		struct
		{
			int AttackedID;
		} attack;

		struct
		{
			unit_type Unit;
		} build;
	};
	int ID;
};

std::vector <std::string> splitstdstring(std::string str, std::string delimiter = " ");
