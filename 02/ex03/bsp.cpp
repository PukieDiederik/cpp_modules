#include "Fixed.hpp"
#include "Point.hpp"


bool bsp(const Point& a, const Point& b, const Point& c, const Point& p)
{
	Fixed s = (a.getX() - c.getX()) * (p.getY() - c.getY()) - (a.getY() - c.getY()) * (p.getX() - c.getX());
	Fixed t = (b.getX() - a.getX()) * (p.getY() - a.getY()) - (b.getY() - a.getY()) * (p.getX() - a.getX());

	if ((s < 0) != (t < 0) && s != 0 && t != 0)
		return false;

	Fixed d = (c.getX() - b.getX()) * (p.getY() - b.getY()) - (c.getY() - b.getY()) * (p.getX() - b.getX());
	return d == Fixed(0) || (d < Fixed(0)) == (s + t <= Fixed(0));
}

//var s = (p0.X - p2.X) * (p.Y - p2.Y) - (p0.Y - p2.Y) * (p.X - p2.X);
//var t = (p1.X - p0.X) * (p.Y - p0.Y) - (p1.Y - p0.Y) * (p.X - p0.X);
//
//if ((s < 0) != (t < 0) && s != 0 && t != 0)
//return false;
//
//var d = (p2.X - p1.X) * (p.Y - p1.Y) - (p2.Y - p1.Y) * (p.X - p1.X);
//return d == 0 || (d < 0) == (s + t <= 0);