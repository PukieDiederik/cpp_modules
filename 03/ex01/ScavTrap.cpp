#include "ScavTrap.hpp"
#include <iostream>

ScavTrap::ScavTrap(const ScavTrap& copy) : ClapTrap(copy)
{
	std::cout << "Scavtrap copy constructor called" << std::endl;
}
ScavTrap::ScavTrap(const std::string& name) :ClapTrap(name)
{
	std::cout << "Scavtrap name constructor called" << std::endl;
	m_max_health = 100;
	m_health = m_max_health;
	m_energy = 50;
	m_attack_damage = 20;
}

// Operators
ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap destructor called" << std::endl;
}

// Functions
void ScavTrap::guardGate()
{
	if (m_health <= 0)
		std::cout << "ScavTrap " << m_name << " is dead" << std::endl;
	else if (m_energy <= 0)
		std::cout << "ScavTrap " << m_name << " is exhausted" << std::endl;
	else
	{
		--m_energy;
		std::cout << "ScavTrap " << m_name << " guarding gate" << std::endl;
	}
}

void ScavTrap::attack(const std::string &target)
{
	if (m_health <= 0)
		std::cout << "ScavTrap " << m_name << " is dead" << std::endl;
	else if (m_energy <= 0)
		std::cout << "ScavTrap " << m_name << " is exhausted" << std::endl;
	else
	{
		--m_energy;
		std::cout << "ScavTrap " << m_name << " attacks " << target << " with a mighty blow for "
				  << m_attack_damage << " damage" << std::endl;
	}
}
