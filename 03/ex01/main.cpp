#include "ScavTrap.hpp"
#include <iostream>

int main()
{
	ScavTrap a("John");
	ScavTrap b(a);
	ScavTrap c("Jeremy");

	std::cout << "\n";

	a = ScavTrap("Jason");
	a.attack("Zombie");

	a.attack("Zombie");
	b.attack("Zombie");
	c.attack("Zombie");

	a.takeDamage(1);
	b.takeDamage(3);
	c.takeDamage(5);

	a.beRepaired(5);
	b.beRepaired(5);
	c.beRepaired(5);
}
