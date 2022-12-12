#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"
#include <string>

class PresidentialPardonForm : public AForm {
	std::string m_target;

	PresidentialPardonForm();
public:
	PresidentialPardonForm(const std::string& target);
	PresidentialPardonForm(const PresidentialPardonForm& copy);

	~PresidentialPardonForm();

	// Operators
	PresidentialPardonForm& operator=(const PresidentialPardonForm& copy);

	// Functions
	void execute(const Bureaucrat &b) const;
};

#endif
