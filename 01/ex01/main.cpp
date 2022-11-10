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
		delete[] zombies;

		zombies = zombieHorde(3, "James");
		delete[] zombies;

		zombies = zombieHorde(0, "Jon");
		delete[] zombies;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}