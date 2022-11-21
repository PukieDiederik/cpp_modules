#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap{
public:
	// Constructors/Destructors
	FragTrap();
	FragTrap(const FragTrap& copy);
	FragTrap(const std::string& name);

	~FragTrap();

	// Operators
	using ClapTrap::operator=;

	// Functions
	void highFivesGuys();
};


#endif
