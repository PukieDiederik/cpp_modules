#include "Weapon.hpp"

// Constructors/Destructors
Weapon::Weapon(std::string type)
	:m_type(type) { }

// Getters/Setters
const std::string& Weapon::getType() const
{
	return m_type;
}
void Weapon::setType(const std::string& new_type)
{
	m_type = new_type;
}
