#ifndef HARL_HPP
#define HARL_HPP

#include <string>

class Harl {
private:
	static std::string m_complain_levels[];
	void (Harl::*m_funcs[4])();

	// Functions
	void debug();
	void info();
	void warning();
	void error();
public:
	// Constructors/Destructors
	Harl();

	// Functions
	int get_level_id(std::string&) const;
	void complain(std::string level);
};

#endif
