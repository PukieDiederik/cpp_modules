#include "Dog.hpp"
#include <iostream>

// Constructors/Destructors
Dog::Dog() // default constructor
{
	std::cout << "Dog default constructor called" << std::endl;
	m_type = "dog";
}

Dog::Dog(const Dog& copy) : Animal()// copy constructor
{
	std::cout << "Dog copy constructor called" << std::endl;
	*this = copy;
}

Dog::~Dog() // destructor
{
	std::cout << "Dog Destructor called" << std::endl;
}

// Operators
Dog& Dog::operator=(const Dog& copy) //copy-assignment
{
	std::cout << "Dog operator=(const Dog&) called" << std::endl;
	m_type = copy.m_type;
	return *this;
}

// Getters/Setters
// Functions
void Dog::makeSound() const
{
	std::cout << "woof woof bark bark!" << std::endl;
}