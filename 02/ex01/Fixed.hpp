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
//	std::ostream& operator<<(std::ostream& out, const Fixed& f); //output

	// Getters/Setters
	int getRawBits() const;
	void setRawBits(const int raw);

	//Functions
	float toFloat() const;
	int toInt() const;
};

//would be so much nicer if we could use friend functions...
std::ostream& operator<<(std::ostream& out, const Fixed& f); //output


#endif
