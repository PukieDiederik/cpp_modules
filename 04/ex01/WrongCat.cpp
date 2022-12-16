#include "WrongCat.hpp"
#include <iostream>

// Constructors/Destructors
WrongCat::WrongCat() // default constructor
{
	std::cout << "Wrong Cat default constructor called" << std::endl;
	m_type = "wrong cat";
}

WrongCat::WrongCat(const WrongCat& copy) :WrongAnimal() // copy constructor
{
	std::cout << "Wrong Cat copy constructor called" << std::endl;
	*this = copy;
}

WrongCat::~WrongCat() // destructor
{

	std::cout << "Wrong Cat destructor called" << std::endl;
}

// Operators
WrongCat& WrongCat::operator=(const WrongCat& copy) //copy-assignment
{
	std::cout << "Wrong Cat operator=(const Cat&) called" << std::endl;
	m_type = copy.m_type;
	return *this;
}

// Getters/Setters
// Functions
void WrongCat::makeSound() const
{
	std::cout << "Meow meow meow" << std::endl;
}
