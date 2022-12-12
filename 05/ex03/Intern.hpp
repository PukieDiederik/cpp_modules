#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"
#include <string>

class Intern {
public:
	// Constructors/Destructors
	Intern();
	Intern(const Intern& copy);

	~Intern();

	// Operators
	Intern& operator=(const Intern& copy);

	// Functions
	AForm* makeForm(std::string name, std::string target);
};


#endif
