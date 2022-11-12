#include "Fixed.hpp"
#include <iostream>
#include <cmath>

// Constructors/Destructors
Fixed::Fixed() // default constructor
{
//	std::cout << "Calling default constructor" << std::endl;
	m_value = 0;
}
Fixed::Fixed(const Fixed& copy) // copy constructor
{
//	std::cout << "Calling copy constructor" << std::endl;
	*this = copy;
}
Fixed::Fixed(const int num)
{
//	std::cout << "Calling int constructor" << std::endl;
	m_value = num << m_scale;
}
Fixed::Fixed(const float num)
{
//	std::cout << "Calling float constructor" << std::endl;
	m_value = roundf((num * (1 << m_scale)));
}

Fixed::~Fixed() // destructor
{
//	std::cout << "Calling destructor" << std::endl;
}

// Operators
Fixed& Fixed::operator=(const Fixed& copy) //copy-assignment
{
//	std::cout << "Calling copy opperator=" << std::endl;
	m_value = copy.m_value;
	return (*this);
}

// Increment operators
Fixed& Fixed::operator++() //pre decrement
{
	++m_value;
	return *this;
}
Fixed& Fixed::operator--() //pre increment
{
	--m_value;
	return *this;
}
Fixed Fixed::operator++(int) //post increment
{
	Fixed tmp(*this);
	++m_value;
	return (tmp);
}
Fixed Fixed::operator--(int) //post decrement
{
	Fixed tmp(*this);
	--m_value;
	return (tmp);
}

// Comparison operators
bool Fixed::operator< (const Fixed& b) const { return m_value <  b.m_value; }
bool Fixed::operator> (const Fixed& b) const { return m_value >  b.m_value; }
bool Fixed::operator<=(const Fixed& b) const { return m_value <= b.m_value; }
bool Fixed::operator>=(const Fixed& b) const { return m_value >= b.m_value; }
bool Fixed::operator==(const Fixed& b) const { return m_value == b.m_value; }
bool Fixed::operator!=(const Fixed& b) const { return m_value != b.m_value; }

// Arithmetic operators
Fixed Fixed::operator+(const Fixed& b)
{
	Fixed tmp;
	tmp.setRawBits(m_value + b.m_value);
	return tmp;
}
Fixed Fixed::operator-(const Fixed& b)
{
	Fixed tmp;
	tmp.setRawBits(m_value - b.m_value);
	return tmp;
}
Fixed Fixed::operator*(const Fixed& b)
{
	Fixed tmp;
	tmp.setRawBits((m_value * b.m_value) >> b.m_scale);
	return tmp;
}
Fixed Fixed::operator/(const Fixed& b)
{
	return Fixed(static_cast<float>(m_value) / b.m_value);
}

std::ostream& operator<<(std::ostream& out, const Fixed& f) //output
{
	out << f.toFloat();
	return out;
}

// Getters/Setters
int Fixed::getRawBits() const
{
//	std::cout << "Get Raw Bits called" << std::endl;
	return m_value;
}

void Fixed::setRawBits(const int raw)
{
//	std::cout << "Set Raw Bits called" << std::endl;
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

Fixed& Fixed::min(Fixed& n1, Fixed& n2) 				  { return n1 < n2 ? n1 : n2; }
Fixed& Fixed::max(Fixed& n1, Fixed& n2)					  { return n1 > n2 ? n1 : n2; }
const Fixed& Fixed::min(const Fixed& n1, const Fixed& n2) { return n1 < n2 ? n1 : n2; }
const Fixed& Fixed::max(const Fixed& n1, const Fixed& n2) { return n1 > n2 ? n1 : n2; }

Fixed Fixed::abs()
{
	if (m_value < 0)
		return (*this * Fixed(-1));
	return (*this);
}
