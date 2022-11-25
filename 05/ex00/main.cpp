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
	a.demote_grade();
	std::cout << a << std::endl;
	a.demote_grade();
	std::cout << a << std::endl;
	a.promote_grade();
	a.promote_grade();
	std::cout << a << std::endl;
	try { a.promote_grade(); }
	catch (std::exception& e) { std::cerr << e.what() << std::endl; }
	std::cout << a << std::endl;

	std::cout << std::endl;

	Bureaucrat b("Subject B", 150);
	std::cout << b << std::endl;
	b.promote_grade();
	std::cout << b << std::endl;
	b.promote_grade();
	std::cout << b << std::endl;
	b.demote_grade();
	b.demote_grade();
	std::cout << b << std::endl;
	try { b.demote_grade(); }
	catch (std::exception& e) { std::cerr << e.what() << std::endl; }
	std::cout << b << std::endl;
}
