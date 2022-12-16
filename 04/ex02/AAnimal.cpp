#include "AAnimal.hpp"
#include <iostream>

// Constructors/Destructors
AAnimal::AAnimal()// default constructor
{
	std::cout << "Animal default constructor called" << std::endl;
	m_type = "animal";
}

AAnimal::AAnimal(const AAnimal& copy) // copy constructor
{
	std::cout << "Animal copy constructor called" << std::endl;
	*this = copy;
}

AAnimal::~AAnimal() // destructor
{
	std::cout << "Animal destructor called" << std::endl;
}

// Operators
AAnimal& AAnimal::operator=(const AAnimal& copy) //copy-assignment
{
	std::cout << "Animal operator= called" << std::endl;
	m_type = copy.m_type;
	return *this;
}

// Getters/Setters
const std::string& AAnimal::getType() const
{
	return m_type;
}
