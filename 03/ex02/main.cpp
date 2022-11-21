#include "FragTrap.hpp"

int main()
{
	FragTrap a;
	FragTrap b(a);
	FragTrap c("John");
	FragTrap d("Jeremy");

	a = FragTrap("Jason");
	a.attack("Zombie");

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

	d.takeDamage(9);
	d.beRepaired(5);

	a.highFivesGuys();
	d.highFivesGuys();
}
