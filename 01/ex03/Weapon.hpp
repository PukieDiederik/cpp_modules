#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <string>

class Weapon {
private:
	std::string m_type;

public:
	// Constructors/Destructors
	Weapon(std::string type);

	// Getters/Setters
	const std::string& getType() const;
	void setType(const std::string& new_type);
};

#endif
