#include "Brain.hpp"
#include <iostream>

// Constructors/Destructors
Brain::Brain() // default constructor
{
	std::cout << "Brain default constructor called" << std::endl;
}

Brain::Brain(const Brain& copy) // copy constructor
{
	std::cout << "Brain copy constructor called" << std::endl;
	*this = copy;
}

Brain::~Brain() // destructor
{
	std::cout << "Brain destructor called" << std::endl;
}

// Operators
Brain& Brain::operator=(const Brain& copy) //copy-assignment
{
	for (int i = 0; i < 100; ++i)
		m_ideas[i] = copy.m_ideas[i];
	return *this;
}

// Getters/Setters
std::string* Brain::getIdea(unsigned int index)
{
	if (index < 100)
		return &m_ideas[index];
	return NULL;
}
void Brain::setIdea(unsigned int index, const std::string& idea)
{
	if (index < 100)
		m_ideas[index] = idea;
}
