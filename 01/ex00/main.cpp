#include <iostream>
#include "Zombie.hpp"

void randomChump(std::string name);
Zombie* newZombie(std::string name);


int main()
{
	std::cout << "> Calling newZombie with name Henry" << std::endl;
	Zombie *a = newZombie("Henry");
	std::cout << "> Calling randomChump with Jhon" << std::endl;
	randomChump("Jhon");
	std::cout << "> Calling Henry's announce" << std::endl;
	a->announce();
	std::cout << "> Calling newZombie with name Michael" << std::endl;
	Zombie *b = newZombie("Michael");
	std::cout << "> Calling Michael's announce" << std::endl;
	b->announce();

	//Dont need to deallocate Jhon because he was allocated in the stack
	std::cout << "> Removing Henry and Michael" << std::endl;
	delete a;
	delete b;
}
