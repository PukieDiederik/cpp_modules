#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie()
	:m_name("no_name")
{
	std::cout << "Creating Zombie Without a name" << std::endl;
}
Zombie::Zombie(std::string& name)
	:m_name(name)
{
	std::cout << "Creating Zombie: " << m_name << std::endl;
}

Zombie::~Zombie()
{
	std::cout << "Destroying Zombie: " << m_name << std::endl;
}

// Getters/Setters
void Zombie::setName(std::string new_name)
{
	m_name = new_name;
}

void Zombie::announce() const
{
	std::cout << m_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}