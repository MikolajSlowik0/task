#include "status.h"

//information about an action
std::ostream& operator<<(std::ostream& os, const status& obj)
{
	os << obj.gold << "\n";

	//printing required format
	for (const auto& element : obj.unit_info)
	{
		os << (element.team ? 'P' : 'E') << " "
			<< static_cast<char> (element.type) << " "
			<< element.ID << " "
			<< element.cords_X << " "
			<< element.cords_Y << " "
			<< element.health << " ";
		
		if (element.type == unit_type::Base)
		{
			os << static_cast<char> (element.production) << std::endl;

			if (element.production == unit_type::Null_production)
			{
				os << '0' << std::endl;
			}
		}
		else
		{
			os << std::endl;
		}
	}

	return os;
}
