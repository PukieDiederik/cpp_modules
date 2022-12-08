#include "FragTrap.hpp"
#include <iostream>

// Constructors/Destructors
FragTrap::FragTrap(const FragTrap& copy) : ClapTrap(copy)
{
	std::cout << "FragTrap copy constructor called" << std::endl;
}
FragTrap::FragTrap(const std::string& name) :ClapTrap(name)
{
	std::cout << "FragTrap name constructor called" << std::endl;
	m_max_health = 100;
	m_health = m_max_health;
	m_energy = 100;
	m_attack_damage = 30;
}

// Operators
FragTrap::~FragTrap()
{
	std::cout << "FragTrap destructor called" << std::endl;
}

// Functions
void FragTrap::highFivesGuys()
{
	if (m_health <= 0)
		std::cout << "FragTrap " << m_name << " is dead" << std::endl;
	else if (m_energy <= 0)
		std::cout << "FragTrap " << m_name << " is exhausted" << std::endl;
	else
	{
		--m_energy;
		std::cout << "FragTrap " << m_name << " wants to high-five" << std::endl;
	}
}
