#include "FragTrap.hpp"

int main()
{
	FragTrap a("John");
	FragTrap b(a);
	FragTrap c("Jeremy");

	a = FragTrap("Jason");
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

	a.highFivesGuys();
}
