#include "game.h"

//splitting command into required format
std::vector <std::string> splitstdstring(const std::string & str, const std::string & delimiter)
{
	std::vector<std::string> splitted_command;

	size_t start = 0;
	size_t end = str.find(delimiter);

	while (end != std::string::npos)
	{
		splitted_command.push_back(str.substr(start, end - start));
		start = end + delimiter.size();
		end = str.find(delimiter, start);
	}

	splitted_command.push_back(str.substr(start, end - start));

	return splitted_command;
}
