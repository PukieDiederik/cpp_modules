#include "Point.hpp"

// Constructors/Destructors
Point::Point() : m_x(0), m_y(0) { }// default constructor
Point::Point(int x, int y) : m_x(x), m_y (y) { }
Point::Point(float x, float y) : m_x(x), m_y (y) { }
Point::Point(const Fixed& x, const Fixed& y) : m_x(x), m_y (y) { }
Point::Point(const Point& copy) {*this = copy; } // copy constructor

Point::~Point() { } // destructor

// Operators
Point& Point::operator=(const Point& copy) //copy-assignment
{
	m_x = copy.m_x;
	m_y = copy.m_y;
	return *this;
}

Fixed Point::getX() const { return m_x; }
Fixed Point::getY() const { return m_y; }
void Point::setX(int x) {  m_x = Fixed(x); }
void Point::setX(const Fixed& x) {  m_x = x; }
void Point::setY(int y) {  m_x = Fixed(y); }
void Point::setY(const Fixed& y) {  m_x = y; }