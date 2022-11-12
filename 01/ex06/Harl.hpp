#ifndef HARL_HPP
#define HARL_HPP

#include <string>

class Harl {
private:
	static std::string m_complain_levels[];
	void (Harl::*m_funcs[4])();

public:
	// Constructors/Destructors
	Harl();
	// Functions
	void debug();
	void info();
	void warning();
	void error();

	int get_level_id(std::string&) const;
	void complain(std::string level);
};

#endif
