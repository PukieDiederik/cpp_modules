#include "WrongAnimal.hpp"
#include <iostream>

// Constructors/Destructors

WrongAnimal::WrongAnimal()// default constructor
{
	std::cout << "Wrong Animal default constructor called" << std::endl;
	m_type = "wrong animal";
}

WrongAnimal::WrongAnimal(const WrongAnimal& copy) // copy constructor
{
	std::cout << "Wrong Animal copy constructor called" << std::endl;
	*this = copy;
}

WrongAnimal::~WrongAnimal() // destructor
{
	std::cout << "Wrong Animal destructor called" << std::endl;
}

// Operators
WrongAnimal& WrongAnimal::operator=(const WrongAnimal& copy) //copy-assignment
{
	std::cout << "Wrong Animal operator= called" << std::endl;
	m_type = copy.m_type;
	return *this;
}

// Getters/Setters
const std::string& WrongAnimal::getType() const
{
	return m_type;
}

// Functions
void WrongAnimal::makeSound() const
{
	std::cout << "this animal doesn't know how to speak" << std::endl;
}
