#ifndef FORM_HPP
#define FORM_HPP

#include <exception>
#include <string>
#include <iostream>

class Bureaucrat;

class Form {
private:
	const std::string m_name;
	bool m_is_signed;
	const int m_req_sign_grade;
	const int m_req_execute_grade;

	// Constructors/Destructors
	Form();

	// Operators
	Form& operator=(const Form& copy);
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
	Form(const std::string& name, int sign_grade, int exec_grade);
	Form(const Form& copy);
	~Form();

	// Getters/Setters
	const std::string& getName() const;
	int getSignGrade() const;
	int getExecGrade() const;
	bool isSigned() const;

	// Functions
	void beSigned(const Bureaucrat& b);
};

std::ostream& operator<<(std::ostream& os, const Form& form);

#endif
