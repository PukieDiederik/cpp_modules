#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

class Point {
private:
	Fixed m_x;
	Fixed m_y;
public:
	// Constructors/Destructors
	Point(); // default constructor
	Point(const Point& copy); // copy constructor
	Point(int x, int y);
	Point(float x, float y);
	Point(const Fixed& x, const Fixed& y);

	~Point(); // destructor

	// Operators
	Point& operator=(const Point& copy); //copy-assignment

	// Getters/Setters
	Fixed getX() const;
	Fixed getY() const;
	void setX(int x);
	void setX(const Fixed& x);
	void setY(int y);
	void setY(const Fixed& y);
};

#endif
