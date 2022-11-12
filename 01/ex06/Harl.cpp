#include "Harl.hpp"
#include <iostream>

Harl::Harl()
{
	m_funcs[0] = &Harl::debug;
	m_funcs[1] = &Harl::info;
	m_funcs[2] = &Harl::warning;
	m_funcs[3] = &Harl::error;
}

std::string Harl::m_complain_levels[] =
{
	"DEBUG",
	"INFO",
	"WARNING",
	"ERROR"
};

int Harl::get_level_id(std::string& s) const
{
	for (int i = 0; (unsigned) i < sizeof(m_complain_levels) / sizeof(m_complain_levels[0]); ++i) {
		if (s == m_complain_levels[i])
			return i;
	}
	return -1;
}
//public:
//// Functions
void Harl::debug()
{
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special- ketchup burger."
				 " I really do!" << std::endl;
}
void Harl::info()
{
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger!"
				 " If you did, I wouldn’t be asking for more!" << std::endl;
}
void Harl::warning()
{
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started"
				 " working here since last month." << std::endl;
}
void Harl::error()
{
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void Harl::complain(std::string level)
{
	int id = Harl::get_level_id(level);
	if (id < 0)
		std::cout << "invalid level" << std::endl;
	else
		(this->*m_funcs[id])();
}