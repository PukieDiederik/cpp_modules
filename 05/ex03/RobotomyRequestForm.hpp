//
// Created by drobert- on 11/29/22.
//

#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include <string>

class RobotomyRequestForm : public AForm{
	std::string m_target;

	RobotomyRequestForm();
public:
	RobotomyRequestForm(const std::string& target);
	RobotomyRequestForm(const RobotomyRequestForm& copy);

	~RobotomyRequestForm();

	// Operators
	RobotomyRequestForm& operator=(const RobotomyRequestForm& copy);

	// Functions
	void execute(const Bureaucrat &b) const;
};


#endif
