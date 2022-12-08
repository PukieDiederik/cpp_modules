#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap{
private:
	FragTrap();
public:
	// Constructors/Destructors
	FragTrap(const FragTrap& copy);
	FragTrap(const std::string& name);

	~FragTrap();

	// Operators
	using ClapTrap::operator=;

	// Functions
	void highFivesGuys();
};


#endif
