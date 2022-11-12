#include "Fixed.hpp"
#include <iostream>

// Constructors/Destructors
Fixed::Fixed() // default constructor
{
	std::cout << "Calling default constructor" << std::endl;
	m_value = 0;
}

Fixed::Fixed(const Fixed& copy) // copy constructor
{
	std::cout << "Calling copy constructor" << std::endl;
	*this = copy;
}

Fixed::~Fixed() // destructor
{
	std::cout << "Calling destructor" << std::endl;
}

// Operators
Fixed& Fixed::operator=(const Fixed& copy) //copy-assignment
{
	std::cout << "Calling copy opperator=" << std::endl;
	m_value = copy.m_value;
	return (*this);
}

// Getters/Setters
int Fixed::getRawBits() const
{
	std::cout << "Get Raw Bits called" << std::endl;
	return m_value;
}

void Fixed::setRawBits(const int raw)
{
	std::cout << "Set Raw Bits called" << std::endl;
	m_value = raw;
}