#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <exception>
#include <iostream>

class Bureaucrat {
private:
	const std::string m_name;
	int m_grade;

	// Constructors/Destructors
	Bureaucrat();

	// Operators
	Bureaucrat& operator=(const Bureaucrat& copy);
public:
	// Exceptions
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
	Bureaucrat(const std::string& name, int grade);
	Bureaucrat(const Bureaucrat& copy);

	~Bureaucrat();

	// Getters/Setters
	const std::string& getName() const;
	int getGrade() const;

	// Functions
	int promote_grade();
	int demote_grade();
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b);

#endif
