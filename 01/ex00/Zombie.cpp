#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie(std::string& name)
	:m_name(name)
{
	std::cout << "Creating Zombie: " << m_name << std::endl;
}

Zombie::~Zombie()
{
	std::cout << "Destroying Zombie: " << m_name << std::endl;
}

void Zombie::announce() const
{
	std::cout << m_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}