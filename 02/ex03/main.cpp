#include "Fixed.hpp"
#include "Point.hpp"
#include <iostream>

bool bsp(const Point& a, const Point& b, const Point& c, const Point& p);

int main( void ) {
	Point a(1, -1);
	Point b(-1, -1);
	Point c(0, 1);

	std::cout << std::boolalpha << bsp(a, b, c, Point(-.5f, -.75f)) << std::endl; // Expected: True
	std::cout << std::boolalpha << bsp(a, b, c, Point(1, 1)) << std::endl; // Expected: False
	std::cout << std::boolalpha << bsp(a, b, c, Point(0.0f, 0.2f)) << std::endl; // Expected: True
	std::cout << std::boolalpha << bsp(a, b, c, Point(0, 1)) << std::endl; // Expected: True
	std::cout << std::boolalpha << bsp(a, b, c, Point(.5f, .0f)) << std::endl; // Expected: True
	std::cout << std::boolalpha << bsp(a, b, c, Point(.5f, .1f)) << std::endl; // Expected: False
	std::cout << std::boolalpha << bsp(a, b, c, Point(.25f, -.5f)) << std::endl; // Expected: True
	std::cout << std::boolalpha << bsp(a, b, c, Point(.75f, -.4f)) << std::endl; // Expected: False
}