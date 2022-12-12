#include "Bureaucrat.hpp"
#include "Intern.hpp"

int main() {
	Bureaucrat b("Ethan" , 1);
	Intern n;
	AForm* f;

	f = n.makeForm("Apples", "Fruit");
	if (f)
	{
		b.signForm(*f);
		b.executeForm(*f);
		delete f;
	}

	f = n.makeForm("Shrubbery Creation", "Home");
	if (f)
	{
		b.signForm(*f);
		b.executeForm(*f);
		delete f;
	}

	f = n.makeForm("Presidential Pardon", "Nilah");
	if (f)
	{
		b.signForm(*f);
		b.executeForm(*f);
		delete f;
	}

	f = n.makeForm("Robotomy Request", "James");
	if (f)
	{
		b.signForm(*f);
		b.executeForm(*f);
		delete f;
	}
}
