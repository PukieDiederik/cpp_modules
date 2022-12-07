#include "Fixed.hpp"
#include <iostream>

int main( void ) {
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

	std::cout << "> Testing increment operators" << std::endl;
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;

	std::cout << b << std::endl;


	std::cout << "> Testing math operators" << std::endl;
	std::cout << Fixed(5.05f) * Fixed(4.3f) << std::endl;
	std::cout << Fixed(-3) * Fixed(2) << std::endl;
	std::cout << Fixed(-5) * Fixed(-3) << std::endl;
	std::cout << Fixed(5.05f) / Fixed(4.3f) << std::endl;
	std::cout << Fixed(5.05f) + Fixed(4.3f) << std::endl;
	std::cout << Fixed(5.05f) - Fixed(4.3f) << std::endl;
	std::cout << Fixed(0) - Fixed(2) << std::endl;


	std::cout << Fixed::max( a, b ) << std::endl;
	std::cout << Fixed::min( a, b ) << std::endl;

	std::cout << "> Testing comparison operators" << std::endl;
	std::cout << std::boolalpha << (Fixed(5.05f) > Fixed(4.3f)) << std::endl;
	std::cout << std::boolalpha << (Fixed(5.05f) < Fixed(4.3f)) << std::endl;

	std::cout << std::boolalpha << (Fixed(5.05f) == Fixed(5.05f)) << std::endl;
	std::cout << std::boolalpha << (Fixed(5.05f) == Fixed(4.3f)) << std::endl;
	std::cout << std::boolalpha << (Fixed(5.05f) != Fixed(4.3f)) << std::endl;

	return 0;
}