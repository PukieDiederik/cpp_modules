#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"
#include <iostream>

int main()
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	Cat *k = new Cat();
	std::cout << j->getType() << std::endl;
	std::cout << i->getType() << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	k->makeSound();
	meta->makeSound();

	delete meta;
	delete j;
	delete i;
	delete k;

	std::cout << "\033[0;32m>>> Wrong animals <<<\033[0m" << std::endl;
	const WrongAnimal* wMeta = new WrongAnimal();
	const WrongAnimal* wi = new WrongCat();
	const WrongCat* wcat = new WrongCat;

	std::cout << wMeta->getType() << std::endl;
	std::cout << wi->getType() << std::endl;
	std::cout << wcat->getType() << std::endl;

	wMeta->makeSound();
	wi->makeSound();
	wcat->makeSound();

	delete wMeta;
	delete wi;
	delete wcat;
}
