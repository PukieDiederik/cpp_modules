#ifndef FIXED_HPP
#define FIXED_HPP

class Fixed {
private:
	int m_value;
	static const int m_scale = 8;

public:
	// Constructors/Destructors
	Fixed(); // default constructor
	Fixed(const Fixed& copy); // copy constructor

	~Fixed(); // destructor

	// Operators
	Fixed& operator=(const Fixed& copy); //copy-assignment

	// Getters/Setters
	int getRawBits() const;
	void setRawBits(const int raw);
};

#endif
