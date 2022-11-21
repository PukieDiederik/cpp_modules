#include "ClapTrap.hpp"
#include <iostream>

ClapTrap::ClapTrap() :m_name("unnamed"), m_max_health(10), m_health(10), m_energy(10), m_attack_damage(0)
{
	std::cout << "ClapTrap default constructor called" << std::endl;
}
ClapTrap::ClapTrap(const ClapTrap& copy)
	:m_name(copy.m_name),
	m_max_health(copy.m_max_health),
	m_health(copy.m_health),
	m_energy(copy.m_energy),
	m_attack_damage(copy.m_attack_damage)
{
	std::cout << "Claptrap copy constructor called" << std::endl;
}
ClapTrap::ClapTrap(const std::string& name)
	:m_name(name), m_max_health(10), m_health(10), m_energy(10), m_attack_damage(0)
{
	std::cout << "Claptrap name constructor called" << std::endl;
}
ClapTrap::~ClapTrap()
{
	std::cout << "Claptrap destructor called" << std::endl;
}

// Operators
ClapTrap& ClapTrap::operator=(const ClapTrap& copy)
{
	m_name = copy.m_name;
	m_max_health = copy.m_max_health;
	m_health = copy.m_health;
	m_energy = copy.m_energy;
	m_attack_damage = copy.m_attack_damage;
	std::cout << "Claptrap copy assignment called" << std::endl;
	return *this;
}

// Getters/Setters
void ClapTrap::attack(const std::string& target)
{
	if (m_health <= 0)
	{
		std::cout << "ClapTrap " << m_name << " is dead" << std::endl;
	}
	else if (m_energy <= 0)
	{
		std::cout << "ClapTrap " << m_name << " is exhausted" << std::endl;
	}
	else
	{
		--m_energy;
		std::cout << "ClapTrap " << m_name << " attacks " << target << " for " << m_attack_damage << " damage"
				  << std::endl;
	}
}
void ClapTrap::takeDamage(unsigned int amount)
{
	if (m_health > 0)
	{
		m_health -= amount;
		std::cout << "ClapTrap " << m_name << " took " << amount << " damage" << std::endl;
		if (m_health <= 0)
			std::cout << "ClapTrap " << m_name << " has died" << std::endl;
		else
			std::cout << "ClapTrap " << m_name << " now has " << m_health << " health left" << std::endl;
	}
	else
		std::cout << "ClapTrap " << m_name << " was already dead, no reason to beat up the dead" << std::endl;
}
void ClapTrap::beRepaired(unsigned int amount)
{
	if (m_health <= 0)
		std::cout << "ClapTrap " << m_name << " is dead" << std::endl;
	else if (m_energy <= 0)
		std::cout << "ClapTrap " << m_name << " is exhausted";
	else
	{
		--m_energy;
		m_health = (m_health + static_cast<int>(amount) > m_max_health) ?
					m_max_health : m_health + static_cast<int>(amount);
		std::cout << "ClapTrap " << m_name << " healed themselves for " << amount << std::endl;
		std::cout << "ClapTrap " << m_name << " is now at " << m_health << " health" << std::endl;
	}
}
