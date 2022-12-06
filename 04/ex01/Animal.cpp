#include "Animal.hpp"
#include <iostream>

// Constructors/Destructors
Animal::Animal()// default constructor
{
	std::cout << "Animal default constructor called" << std::endl;
	m_type = "animal";
}

Animal::Animal(const Animal& copy) // copy constructor
{
	std::cout << "Animal copy constructor called" << std::endl;
	*this = copy;
}

Animal::~Animal() // destructor
{
	std::cout << "Animal destructor called" << std::endl;
}

// Operators
Animal& Animal::operator=(const Animal& copy) //copy-assignment
{
	std::cout << "Animal operator= called" << std::endl;
	m_type = copy.m_type;
	return *this;
}

// Getters/Setters
const std::string& Animal::getType() const
{
	return m_type;
}

// Functions
void Animal::makeSound() const
{
	std::cout << "this animal doesn't know how to speak" << std::endl;
}