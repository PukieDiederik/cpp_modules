#include "Cat.hpp"
#include "Dog.hpp"
#include <iostream>

int main()
{
	std::cout << "Constructor/Destructor testing:" << std::endl;
	AAnimal* a[6];
	for(int i = 0; i < 3; ++i)
		a[i] = new Dog();
	for(int i = 3; i < 6; ++i)
		a[i] = new Cat();

	a[1]->makeSound(); // dog
	a[2]->makeSound(); // dog
	a[5]->makeSound(); // cat

	for (int i = 0; i < 6; ++i)
		delete a[i];

	std::cout << "Testing for deep copies" << std::endl;
	Cat *b = new Cat(); // Chose cat because Cat > Dog
	b->getBrain()->setIdea(0, "Amazing Ideas");
	b->getBrain()->setIdea(5, "Wow!!");

	std::cout << "b[0]: " << *b->getBrain()->getIdea(0) << std::endl;
	std::cout << "b[5]: " << *b->getBrain()->getIdea(5) << std::endl;

	Cat c = *b;
	std::cout << "c[0]: " << *c.getBrain()->getIdea(0) << std::endl;
	std::cout << "c[5]: " << *c.getBrain()->getIdea(5) << std::endl;

	c.getBrain()->setIdea(5, "New Idea");
	std::cout << "b[5]: " << *b->getBrain()->getIdea(5) << std::endl;
	std::cout << "c[5]: " << *c.getBrain()->getIdea(5) << std::endl;
	delete b;

}