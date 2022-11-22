#include "Zombie.hpp"
#include <stdexcept>
#include <string>

Zombie* zombieHorde(int n, std::string name)
{
	if (n <= 0)
		throw std::runtime_error("Invalid horde size");
	Zombie *zombies = new Zombie[n]();
	for(int i = 0; i < n; ++i)
	{
		zombies[i].setName(name);
	}
	return zombies;
}
