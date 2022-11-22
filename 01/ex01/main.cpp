#include "Zombie.hpp"
#include <exception>
#include <iostream>

Zombie* zombieHorde(int n, std::string name);

int main()
{
	Zombie *zombies;

	try
	{
		zombies = zombieHorde(5, "Josh");
		for (int i = 0; i < 5; ++i)
			zombies[i].announce();
		delete[] zombies;

		zombies = zombieHorde(3, "James");
		for (int i = 0; i < 3; ++i)
			zombies[i].announce();
		delete[] zombies;

		zombies = zombieHorde(0, "Jon");
		delete[] zombies;

		//never executes this
		zombies = zombieHorde(-1, "Jeniffer");
		delete[] zombies;
	}
	catch (std::exception &e)
	{
		std::cout << "ERROR: " << e.what() << std::endl;
	}
}
