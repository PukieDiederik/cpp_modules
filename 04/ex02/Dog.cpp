#include "Dog.hpp"
#include <iostream>

// Constructors/Destructors
Dog::Dog() : AAnimal(), m_brain(new Brain())// default constructor
{
	std::cout << "Dog default constructor called" << std::endl;
	m_type = "dog";
}

Dog::Dog(const Dog& copy) : AAnimal(), m_brain(NULL)// copy constructor
{
	std::cout << "Dog copy constructor called" << std::endl;
	*this = copy;
}

Dog::~Dog() // destructor
{
	std::cout << "Dog Destructor called" << std::endl;
	if (m_brain)
		delete m_brain;
}

// Operators
Dog& Dog::operator=(const Dog& copy) //copy-assignment
{
	std::cout << "Dog operator=(const Dog&) called" << std::endl;
	m_type = copy.m_type;
	if (m_brain)
		delete m_brain;
	m_brain = new Brain(*copy.m_brain);
	return *this;
}

// Getters/Setters
Brain* Dog::getBrain() { return m_brain; }

// Functions
void Dog::makeSound() const
{
	std::cout << "woof woof bark bark!" << std::endl;
}