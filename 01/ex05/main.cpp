#include "Harl.hpp"
#include <iostream>

int main()
{
	Harl h;
	h.complain("DEBUG");
	std::cout << "---" << std::endl;
	h.complain("INFO");
	std::cout << "---" << std::endl;
	h.complain("");
	std::cout << "---" << std::endl;
	h.complain("ERROR");
	std::cout << "---" << std::endl;
	h.complain("Warning");
	std::cout << "---" << std::endl;
	h.complain("WARNING");
}
