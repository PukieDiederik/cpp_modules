#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

// Constructors/Destructors
Intern::Intern() { }
Intern::Intern(const Intern& copy) { (void) copy; }

Intern::~Intern() { }

// Operators
Intern& Intern::operator=(const Intern& copy) { (void) copy; return *this; }

// Functions
AForm* Intern::makeForm(std::string name, std::string target)
{
	AForm* arr[] =
	{
		new ShrubberyCreationForm(target),
		new RobotomyRequestForm(target),
		new PresidentialPardonForm(target)
	};

	AForm* ret = NULL;
	for (unsigned int i = 0; i < sizeof(arr) / sizeof(AForm *); ++i)
	{
		if (!ret && name == arr[i]->getName())
			ret = arr[i];
		else
			delete arr[i];
	}
	if (!ret)
		std::cerr << "Invalid Form" << std::endl;
	else
		std::cout << "Intern created: " << ret->getName() << " form" << std::endl;
	return ret;
}
