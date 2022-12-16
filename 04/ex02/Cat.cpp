#include "Cat.hpp"
#include <iostream>

// Constructors/Destructors
Cat::Cat() :AAnimal(), m_brain(new Brain())// default constructor
{
	std::cout << "Cat default constructor called" << std::endl;
	m_type = "cat";
}

Cat::Cat(const Cat& copy) :AAnimal(), m_brain(NULL)// copy constructor
{
	std::cout << "Cat copy constructor called" << std::endl;
	*this = copy;
}

Cat::~Cat() // destructor
{
	std::cout << "Cat destructor called" << std::endl;
	if (m_brain)
		delete m_brain;
}

// Operators
Cat& Cat::operator=(const Cat& copy) //copy-assignment
{
	std::cout << "Cat operator=(const Cat&) called" << std::endl;
	m_type = copy.m_type;
	if (m_brain)
		delete m_brain;
	m_brain = new Brain(*copy.m_brain);
	std::cout << "end" << std::endl;
	return *this;
}

// Getters/Setters
Brain* Cat::getBrain() { return m_brain; }

// Functions
void Cat::makeSound() const
{
	std::cout << "Meow meow meow" << std::endl;
}
