#include <iostream>
#include "whatever.hpp"
#include <stack>

class A
{

};

int main()
{
	int a = 5;
	const int b = 3;
	int c = 7;

	::swap(a, c);
	std::cout << a << ", " << b << std::endl;

	std::cout << ::min(a, b) << std::endl;
	std::cout << ::min(6,6) << std::endl;
	std::cout << ::max(a, b) << std::endl;
	std::cout << ::max(6,6) << std::endl;

	a = 5;
	c = 5;
	std::cout << &a << ", " << &c << std::endl;
	std::cout << &::min(a,c) << ", " << &::max(a,c) << std::endl;
}