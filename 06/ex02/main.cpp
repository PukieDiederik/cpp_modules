#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <exception>
#include <iostream>
#include <cstdlib>

Base* generate(void)
{
	srand(clock());
	int i = rand() % 3;
	switch(i)
	{
		case 0:
			std::cout << "Generated A" << std::endl;
			return new A();
		case 1:
			std::cout << "Generated B" << std::endl;
			return new B();
		case 2:
			std::cout << "Generated C" << std::endl;
			return new C();
		default:
			return NULL;
	}
}

void identify(Base* p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "Identified as A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "Identified as B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "Identified as C" << std::endl;
	else
		std::cerr << "could not identify type\n";
}

void identify(Base& p)
{
	try
	{
		dynamic_cast<A&>(p);
		std::cout << "Identified as A" << std::endl;
	}
	catch (std::exception&)
	{
		try
		{
			dynamic_cast<B&>(p);
			std::cout << "Identified as B" << std::endl;
		}
		catch (std::exception &)
		{
			try
			{
				dynamic_cast<C&>(p);
				std::cout << "Identified as C" << std::endl;
			}
			catch (std::exception&)
			{
				std::cerr << "could not identify type\n";
			}
		}
	}
}

int main ()
{
	A a;
	B b;
	C c;

	identify(a);
	identify(b);
	identify(c);

	std::cout << "\n---\n" << std::endl;

	identify(&a);
	identify(&b);
	identify(&c);

	std::cout << "\n---\n" << std::endl;

	for(int i = 0; i < 10; ++i)
	{
		Base *b = generate();
		identify(b);
		delete b;
	}
}