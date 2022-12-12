#ifndef FORM_HPP
#define FORM_HPP

#include <exception>
#include <string>
#include <iostream>

class Bureaucrat;

class AForm {
private:
	// Constructors/Destructors
	AForm();

	// Operators
	AForm& operator=(const AForm& copy);

protected:
	const std::string m_name;
	bool m_is_signed;
	const int m_req_sign_grade;
	const int m_req_execute_grade;

	void canExecuteThrow(const Bureaucrat& b) const;

public:
	class GradeTooHighException : public std::exception
	{
	public:
		// Constructors/Destructors
		GradeTooHighException();
		GradeTooHighException(const GradeTooHighException& copy);

		virtual ~GradeTooHighException() throw();

		// Operators
		GradeTooHighException& operator=(const GradeTooHighException& copy);

		// Functions
		virtual const char* what() const throw();
	};

	class GradeTooLowException : public std::exception
	{
	public:
		// Constructors/Destructors
		GradeTooLowException();
		GradeTooLowException(const GradeTooLowException& copy);

		virtual ~GradeTooLowException() throw();

		// Operators
		GradeTooLowException& operator=(const GradeTooLowException& copy);

		// Functions
		virtual const char* what() const throw();
	};

	// Constructors/Destructors
	AForm(const std::string& name, int sign_grade, int exec_grade);
	AForm(const AForm& copy);
	virtual ~AForm();

	// Getters/Setters
	const std::string& getName() const;
	int getSignGrade() const;
	int getExecGrade() const;
	bool isSigned() const;

	// Functions
	void beSigned(const Bureaucrat& b);
	virtual void execute(const Bureaucrat& b) const = 0;
};

std::ostream& operator<<(std::ostream& os, const AForm& form);

#endif
