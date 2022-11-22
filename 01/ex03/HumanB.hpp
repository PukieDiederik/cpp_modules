#ifndef HUMANB_HPP
#define HUMANB_HPP

#include "Weapon.hpp"
#include <string>

class HumanB {
private:
	Weapon* m_weapon;
	std::string m_name;

public:
	HumanB(const std::string& name);

	void setWeapon(Weapon& weapon);

	void attack() const;
};

#endif
