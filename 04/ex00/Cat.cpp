#include "Cat.hpp"
#include <iostream>

// Constructors/Destructors
Cat::Cat() // default constructor
{
	std::cout << "Cat default constructor called" << std::endl;
	m_type = "cat";
}

Cat::Cat(const Cat& copy) :Animal() // copy constructor
{
	std::cout << "Cat copy constructor called" << std::endl;
	*this = copy;
}

Cat::~Cat() // destructor
{

	std::cout << "Cat destructor called" << std::endl;
}

// Operators
Cat& Cat::operator=(const Cat& copy) //copy-assignment
{
	std::cout << "Cat operator=(const Cat&) called" << std::endl;
	m_type = copy.m_type;
	return *this;
}

// Getters/Setters
// Functions
void Cat::makeSound() const
{
	std::cout << "Meow meow meow" << std::endl;
}