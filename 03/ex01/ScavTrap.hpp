#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap{
public:
	// Constructors/Destructors
	ScavTrap();
	ScavTrap(const ScavTrap& copy);
	ScavTrap(const std::string& name);

	~ScavTrap();

	// Operators
	using ClapTrap::operator=;

	// Functions
	void guardGate();
	void attack(const std::string &target);
};


#endif
