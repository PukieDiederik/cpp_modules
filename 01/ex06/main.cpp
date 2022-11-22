#include "Harl.hpp"
#include <iostream>
#include <string>

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "Incorrect usage: ./harlFilter [log_level]\n";
		return (1);
	}
	Harl h;
	std::string s = argv[1];
	switch (h.get_level_id(s))
	{
		case 0:
			h.complain("DEBUG");
			//falls through
		case 1:
			h.complain("INFO");
			//falls through
		case 2:
			h.complain("WARNING");
			//falls through
		case 3:
			h.complain("ERROR");
			break;
		default:
			std::cerr << "Invalid Debug level\n";
	}
}
