#include "Fixed.hpp"
#include <iostream>
#include <cmath>

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

Fixed::Fixed(const int num)
{
	std::cout << "Calling int constructor" << std::endl;
	m_value = num << m_scale;
}
Fixed::Fixed(const float num)
{
	std::cout << "Calling float constructor" << std::endl;
	m_value = roundf((num * (1 << m_scale)));
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

std::ostream& operator<<(std::ostream& out, const Fixed& f) //output
{
	out << f.toFloat();
	return out;
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

//Functions
int Fixed::toInt() const
{
	return m_value >> m_scale;
}
float Fixed::toFloat() const
{
	return (static_cast<float>(m_value) / (1 << m_scale));
}