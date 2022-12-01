#include "ClapTrap.hpp"

int main()
{
	ClapTrap a;
	ClapTrap b(a);
	ClapTrap c("John");
	ClapTrap d("Jeremy");

	a = ClapTrap("Jason");

	a.attack("Zombie");
	b.attack("Zombie");
	c.attack("Zombie");
	d.attack("Zombie");

	a.takeDamage(1);
	b.takeDamage(3);
	c.takeDamage(5);
	d.takeDamage(7);

	a.beRepaired(5);
	b.beRepaired(5);
	c.beRepaired(5);
	d.beRepaired(5);

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

	d.takeDamage(9);
	d.beRepaired(5);
}
