#include "RobotomyRequestForm.hpp"
#include <cstdlib>

RobotomyRequestForm::RobotomyRequestForm(const std::string& target)
		: AForm("Robotomy Request", 72, 45), m_target(target) { }
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& copy)
		: AForm(copy), m_target(copy.m_target) { }

RobotomyRequestForm::~RobotomyRequestForm() { }

// Operators
RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& copy)
{
	m_is_signed = copy.m_is_signed;
	return *this;
}

// Functions
void RobotomyRequestForm::execute(const Bureaucrat& b) const
{
	canExecuteThrow(b);
	srand(clock());
	if (rand() & 1)
		std::cout << m_target << " has been robotomized successfully" << std::endl;
	else
		std::cout << m_target << " failed to be robotomized" << std::endl;
}
