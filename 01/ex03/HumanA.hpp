#ifndef HUMANA_HPP
#define HUMANA_HPP

#include "Weapon.hpp"
#include <string>

class HumanA {
private:
	Weapon& m_weapon;
	std::string m_name;

public:
	HumanA(const std::string& name, Weapon& weapon);

	void attack() const;
};

#endif
