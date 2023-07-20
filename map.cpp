#include "map.h"
#include <string>
#include <streambuf>
#include <fstream>

static std::string load_file(const std::string& filename) 
{

	if (auto stream = std::ifstream(filename); stream) {

		return {
			std::istreambuf_iterator<char> { stream },
			std::istreambuf_iterator<char> {}
		};
	}

	return "";
}

void map::load_map()
{
	std::string map_size = load_file("../mapa.txt");

	//subtracting '0' to get correct value corresponding to a digit
	std::string size_X = std::to_string(map_size[0] - '0') + std::to_string(map_size[1] - '0');
	std::string size_Y = std::to_string(map_size[3] - '0') + std::to_string(map_size[4] - '0');

	//resize internal vectors to match map's dimensions
	data.resize(stoi(size_Y));
	for (int i = 0; i < stoi(size_Y); i++)
	{
		data[i].resize(stoi(size_X));
	}


	int skip = 0;

	//starting from 6 because we used first 2 lines to define size of the map
	for (int i = 6; i < map_size.size(); i++)
	{
		switch (map_size[i])
		{
		case '0':
		{
			data[(i - skip - 6) / width][(i - skip - 6) % width] = tile::road;
			break;
		}
		case '9':
		{
			data[(i - skip - 6) / width][(i - skip - 6) % width] = tile::obstacle;
			break;
		}
		case '1':
		{
			data[(i - skip - 6) / width][(i - skip - 6) % width] = tile::base_blue;
			break;
		}
		case '2':
		{
			data[(i - skip - 6) / width][(i - skip - 6) % width] = tile::base_red;
			break;
		}
		case '6':
		{
			data[(i - skip - 6) / width][(i - skip - 6) % width] = tile::mine;
			break;
		}
		case '\n':
		{
			skip++;
			break;
		}
		default:
			break;
		}
	}
}
