#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <string>

class ClapTrap {
private:
	std::string m_name;
	int m_max_health;
	int m_health;
	int m_energy;
	int m_attack_damage;
public:
	// Constructor/Destructor
	ClapTrap();
	ClapTrap(const ClapTrap& copy);
	ClapTrap(const std::string& name);
	ClapTrap(const std::string& name, int max_health, int health, int energy, int attack_damage);

	~ClapTrap();

	// Operators
	ClapTrap& operator=(const ClapTrap&);

	// Getters/Setters
	void attack(const std::string& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
};


#endif
