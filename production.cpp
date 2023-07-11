#include "production.h"


void Production::production(unit_type type, status& ob)
{
	//checking if we have enough gold to produce a unit
	if (ob.gold_amount() >= unit_charge(type).first)
	{
		//decreasing amount of stored gold by unit's production cost
		ob.gold_change(unit_charge(type).first);

		unit parameters;

		parameters.type = type;

		switch (type)
		{
			case unit_type::Knight:
				parameters.team = 0;
				parameters.ID = unit_count++;
				parameters.cords_X = 0;
				parameters.cords_Y = 0;
				parameters.health = 70;
				parameters.speed = 5;
				parameters.range = 1;

				break;
			case unit_type::Swordsman:
				parameters.team = 0;
				parameters.ID = unit_count++;
				parameters.cords_X = 0;
				parameters.cords_Y = 0;
				parameters.health = 60;
				parameters.speed = 2;
				parameters.range = 1;

				break;
			case unit_type::Archer:
				parameters.team = 0;
				parameters.ID = unit_count++;
				parameters.cords_X = 0;
				parameters.cords_Y = 0;
				parameters.health = 40;
				parameters.speed = 2;
				parameters.range = 7;

				break;
			case unit_type::Pikeman:
				parameters.team = 0;
				parameters.ID = unit_count++;
				parameters.cords_X = 0;
				parameters.cords_Y = 0;
				parameters.health = 50;
				parameters.speed = 2;
				parameters.range = 2;

				break;
			case unit_type::Ram:
				parameters.team = 0;
				parameters.ID = unit_count++;
				parameters.cords_X = 0;
				parameters.cords_Y = 0;
				parameters.health = 90;
				parameters.speed = 2;
				parameters.range = 1;

				break;
			case unit_type::Catapult:
				parameters.team = 0;
				parameters.ID = unit_count++;
				parameters.cords_X = 0;
				parameters.cords_Y = 0;
				parameters.health = 50;
				parameters.speed = 2;
				parameters.range = 7;

				break;
			case unit_type::Worker:
				parameters.team = 0;
				parameters.ID = unit_count++;
				parameters.cords_X = 0;
				parameters.cords_Y = 0;
				parameters.health = 20;
				parameters.speed = 2;
				parameters.range = 1;

				break;
			case unit_type::Base:
				parameters.team = 0;
				parameters.ID = unit_count++;
				parameters.cords_X = 0;
				parameters.cords_Y = 0;
				parameters.speed = 0;
				parameters.health = 200;

				break;
			default:
				break;
		}

		ob.push_unit(parameters);
	}
	else
	{
		//Report an error 
	}
}

//first element is unit cost and second is unit build time
std::pair<int, int> Production::unit_charge(unit_type unit)
{
	switch (unit)
	{
	case unit_type::Knight:
		return { 400, 5 };

	case unit_type::Swordsman:
		return { 250, 3 };

	case unit_type::Archer:
		return { 250, 3 };

	case unit_type::Pikeman:
		return { 200, 3 };

	case unit_type::Ram:
		return { 500, 4 };

	case unit_type::Catapult:
		return { 800, 6 };

	case unit_type::Worker:
		return { 100, 2 };

	default:
		break;
	}
}
