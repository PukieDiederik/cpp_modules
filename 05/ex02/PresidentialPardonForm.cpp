#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(const std::string& target)
	: AForm("Presidential Pardon", 25, 5), m_target(target) { }
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& copy)
	: AForm(copy), m_target(copy.m_target) { }

PresidentialPardonForm::~PresidentialPardonForm() { }

// Operators
PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& copy)
{
	m_is_signed = copy.m_is_signed;
	return *this;
}

// Functions
void PresidentialPardonForm::execute(const Bureaucrat& b) const
{
	canExecuteThrow(b);
	std::cout << m_target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}
