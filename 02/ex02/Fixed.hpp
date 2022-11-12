#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed {
private:
	int m_value;
	static const int m_scale = 8;

public:
	// Constructors/Destructors
	Fixed(); // default constructor
	Fixed(const Fixed& copy); // copy constructor
	Fixed(const int num);
	Fixed(const float num);

	~Fixed(); // destructor

	// Operators
	Fixed& operator=(const Fixed& copy); //copy-assignment
	Fixed& operator++(); //pre decrement
	Fixed& operator--(); //pre increment
	Fixed operator++(int); //post increment
	Fixed operator--(int); //post decrement

	bool operator<(const Fixed& b) const;
	bool operator>(const Fixed& b) const;
	bool operator<=(const Fixed& b) const;
	bool operator>=(const Fixed& b) const;
	bool operator==(const Fixed& b) const;
	bool operator!=(const Fixed& b) const;

	Fixed operator+(const Fixed& b);
	Fixed operator-(const Fixed& b);
	Fixed operator*(const Fixed& b);
	Fixed operator/(const Fixed& b);

	// Getters/Setters
	int getRawBits() const;
	void setRawBits(const int raw);

	//Functions
	float toFloat() const;
	int toInt() const;

	static Fixed& min(Fixed& n1, Fixed& n2);
	static const Fixed& min(const Fixed& n1, const Fixed& n2);
	static Fixed& max(Fixed& n1, Fixed& n2);
	static const Fixed& max(const Fixed& n1, const Fixed& n2);
};

//would be so much nicer if we could use friend functions...
std::ostream& operator<<(std::ostream& out, const Fixed& f); //output


#endif
