#include "game.h"

//splitting command into required format
std::vector <std::string> splitstdstring(std::string str, std::string delimiter)
{
	std::vector<std::string> splitted_command;

	int start = 0;
	int end = str.find(delimiter);

	while (end != -1) 
	{
		splitted_command.push_back(str.substr(start, end - start));
		start = end + delimiter.size();
		end = str.find(delimiter, start);
	}

	splitted_command.push_back(str.substr(start, end - start));

	return splitted_command;
}
