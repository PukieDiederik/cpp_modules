#include "Zombie.hpp"
#include <string>

//Please let me use a string reference
Zombie* newZombie(std::string name)
{
	return (new Zombie(name));
}
