#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#include <string>

class ShrubberyCreationForm : public AForm {
private:
	const std::string m_target;

	ShrubberyCreationForm();
public:
	// Constructors/Destructors
	ShrubberyCreationForm(const std::string& target);
	ShrubberyCreationForm(ShrubberyCreationForm& copy);

	~ShrubberyCreationForm();

	// Operators
	ShrubberyCreationForm& operator=(ShrubberyCreationForm& copy);

	// Functions
	virtual	void execute(const Bureaucrat &b) const;
};


#endif
