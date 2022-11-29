#include "Bureaucrat.hpp"
#include <exception>
#include <iostream>

int main()
{
	std::cout << ">>> Testing initialization <<<" << std::endl;
	try { Bureaucrat b("John", 4); std::cout << b << std::endl;}
	catch (std::exception& e) { std::cerr << e.what() << std::endl; }
	try { Bureaucrat b("Jack", 150); std::cout << b << std::endl;}
	catch (std::exception& e) { std::cerr << e.what() << std::endl; }
	try { Bureaucrat b("James", 1); std::cout << b << std::endl;}
	catch (std::exception& e) { std::cerr << e.what() << std::endl; }
	try { Bureaucrat b("Jeremy", 0); std::cout << b << std::endl;}
	catch (std::exception& e) { std::cerr << e.what() << std::endl; }
	try { Bureaucrat b("Jonas", 4); std::cout << b << std::endl;}
	catch (std::exception& e) { std::cerr << e.what() << std::endl; }
	try { Bureaucrat b("Clint", -1); std::cout << b << std::endl;}
	catch (std::exception& e) { std::cerr << e.what() << std::endl; }
	try { Bureaucrat b("Mary", 151); std::cout << b << std::endl;}
	catch (std::exception& e) { std::cerr << e.what() << std::endl; }

	std::cout << ">>> Testing promotion/demotion <<<" << std::endl;

	Bureaucrat a("Subject A", 1);
	std::cout << a << std::endl;
	a.demoteGrade();
	std::cout << a << std::endl;
	a.demoteGrade();
	std::cout << a << std::endl;
	a.promoteGrade();
	a.promoteGrade();
	std::cout << a << std::endl;
	try { a.promoteGrade(); }
	catch (std::exception& e) { std::cerr << e.what() << std::endl; }
	std::cout << a << std::endl;

	std::cout << std::endl;

	Bureaucrat b("Subject B", 150);
	std::cout << b << std::endl;
	b.promoteGrade();
	std::cout << b << std::endl;
	b.promoteGrade();
	std::cout << b << std::endl;
	b.demoteGrade();
	b.demoteGrade();
	std::cout << b << std::endl;
	try { b.demoteGrade(); }
	catch (std::exception& e) { std::cerr << e.what() << std::endl; }
	std::cout << b << std::endl;

	std::cout << ">>> Testing using copy constructor <<<" << std::endl;
	Bureaucrat c(a);
	std::cout << c << std::endl;
	c.demoteGrade();
	std::cout << a << "; " << c << std::endl;
	Bureaucrat d(b);
	std::cout << d << std::endl;
	d.promoteGrade();
	std::cout << b << "; " << d << std::endl;
}
