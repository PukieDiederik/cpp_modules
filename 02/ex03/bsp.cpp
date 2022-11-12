#include "Fixed.hpp"
#include "Point.hpp"

static Fixed get_area(const Point& a, const Point& b, const Point& c)
{
	return (a.getX() * (b.getY() - c.getY())
		  + b.getX() * (c.getY() - a.getY())
		  + c.getX() * (a.getY() - b.getY())).abs() * Fixed(0.5f);
}

bool bsp(const Point& a, const Point& b, const Point& c, const Point& p)
{
	Fixed totalArea = get_area(a, b, c);
	return get_area(a,b,p) +  get_area(a,c,p) + get_area(c,b,p) == totalArea;
}