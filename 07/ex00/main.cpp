#include <iostream>
#include "whatever.hpp"
#include <stack>

class A
{

};

int main()
{
	int a = 5;
	int b = 3;

	::swap(a, b);
	std::cout << a << ", " << b << std::endl;

	std::cout << ::min(a, b) << std::endl;
	std::cout << ::min(6,6) << std::endl;
	std::cout << ::max(a, b) << std::endl;
	std::cout << ::max(6,6) << std::endl;

	a = 5;
	b = 5;
	std::cout << &a << ", " << &b << std::endl;
	std::cout << &::min(a,b) << ", " << &::max(a,b) << std::endl;
}