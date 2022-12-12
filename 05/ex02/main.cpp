#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main() {
	std::cout << "\033[0;36m>>>>> Testing Forms <<<<<\033[0m" << std::endl;
	std::cout << "\033[0;32m>>> Testing Presidential Pardons <<<\033[0m" << std::endl;
	AForm *f = new PresidentialPardonForm("Bob");
	Bureaucrat b("James", 3);
	Bureaucrat c("Nick", 45);
	c.signForm(*f);
	b.signForm(*f);
	b.signForm(*f);
	c.executeForm(*f);
	b.executeForm(*f);
	delete f;

	std::cout << "\033[0;32m>>> Testing Robotomy Requests <<<\033[0m" << std::endl;
	f = new RobotomyRequestForm("Jack");
	b.signForm(*f);
	b.executeForm(*f);
	b.executeForm(*f);
	b.executeForm(*f);
	b.executeForm(*f);
	b.executeForm(*f);
	delete f;

	std::cout << "\033[0;32m>>> Testing Shrubbery Creations <<<\033[0m" << std::endl;
	f = new ShrubberyCreationForm("Home");
	b.signForm(*f);
	b.executeForm(*f);
	b.executeForm(*f);
	b.executeForm(*f);
	delete f;
}
