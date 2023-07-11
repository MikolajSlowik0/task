#include "commands.h"
#include <string>

//loading commands from file 
std::istream& operator>>(std::istream& os, commands& obj)
{
	//loop through each line
	for (std::string line; std::getline(os, line); )
	{
		//split string into tokens
		std::vector<std::string> com { splitstdstring(line) };

		//checking if command is of a correct size
		if (com.size() == 3 || com.size() == 4)
		{
			continue;
		}

		int id = stoi(com[0]);
		int ACTION = com[1][0];

		Command ob2;

		ob2.ID = id;
		ob2.type = static_cast<actions>(ACTION);

		switch (ACTION)
		{
		case 'M':
		{
			ob2.move.X = stoi(com[2]);
			ob2.move.Y = stoi(com[3]);
			break;
		}
		case 'A':
		{
			ob2.attack.AttackedID = stoi(com[3]);
			break;
		}
		case 'B':
		{
			ob2.build.Unit = static_cast<unit_type>(stoi(com[3]));
			break;
		}
		default:
			break;
		}

		obj.command_queue.push_back(ob2);
	}

	return os;
}
