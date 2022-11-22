#include "HumanB.hpp"
#include <iostream>

HumanB::HumanB(const std::string &name)
	:m_weapon(NULL), m_name(name) { }

void HumanB::setWeapon(Weapon& weapon)
{
	m_weapon = &weapon;
}

void HumanB::attack() const
{
	if (!m_weapon)
		std::cout << m_name << " doesn't have a weapon, so they use their hands!" << std::endl;
	else
		std::cout << m_name << " attacks with their " << m_weapon->getType() << std::endl;
}
