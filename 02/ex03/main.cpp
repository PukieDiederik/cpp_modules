#include "Fixed.hpp"
#include "Point.hpp"
#include <iostream>

bool bsp(const Point& a, const Point& b, const Point& c, const Point& p);

int main( void ) {
	Point a(1,-1);
	Point b(-1,-1);
	Point c(0, 1);
	Point d(-.5f, -0.75f);

	std::cout << bsp(a,b,c,d) << std::endl;
}