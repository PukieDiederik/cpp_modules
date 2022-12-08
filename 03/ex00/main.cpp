#include "ClapTrap.hpp"
#include <iostream>

int main()
{
	ClapTrap a("John");
	ClapTrap b(a);
	ClapTrap c("Jeremy");

	a = ClapTrap("Jason");

	std::cout << "\n";

	a.attack("Zombie");
	b.attack("Zombie");
	c.attack("Zombie");

	std::cout << "\n";

	a.takeDamage(1);
	b.takeDamage(3);
	c.takeDamage(5);

	a.beRepaired(5);
	b.beRepaired(5);
	c.beRepaired(5);

	std::cout << "\n";

	a.attack("Lowering energy");
	a.attack("Lowering energy");
	a.attack("Lowering energy");
	a.attack("Lowering energy");
	a.attack("Lowering energy");
	a.attack("Lowering energy");
	a.attack("Lowering energy");
	a.attack("Lowering energy");
	a.attack("Should not print"); // Shouldn't have any energy left
	a.attack("Should not print");

	std::cout << "\n";

	b.takeDamage(11);
	b.beRepaired(3);
}
