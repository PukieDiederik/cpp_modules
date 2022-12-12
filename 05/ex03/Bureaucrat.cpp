#include "Bureaucrat.hpp"
#include <exception>
#include <iostream>

// Exceptions
//  Grade too high
Bureaucrat::GradeTooHighException::GradeTooHighException() {}
Bureaucrat::GradeTooHighException::GradeTooHighException(const Bureaucrat::GradeTooHighException& copy)
{
	*this = copy;
}
Bureaucrat::GradeTooHighException::~GradeTooHighException() throw() {}

Bureaucrat::GradeTooHighException& Bureaucrat::GradeTooHighException::operator=(
		const Bureaucrat::GradeTooHighException& copy
		)
{
	std::exception::operator=(copy);
	return *this;
}

const char* Bureaucrat::GradeTooHighException::what() const throw() { return "Grade is too high"; }

//  Grade too low
Bureaucrat::GradeTooLowException::GradeTooLowException() { }
Bureaucrat::GradeTooLowException::GradeTooLowException(const Bureaucrat::GradeTooLowException& copy)
{
	*this = copy;
}
Bureaucrat::GradeTooLowException::~GradeTooLowException() throw(){}

Bureaucrat::GradeTooLowException& Bureaucrat::GradeTooLowException::operator=(
		const Bureaucrat::GradeTooLowException& copy
		)
{
	std::exception::operator=(copy);
	return *this;
}

const char* Bureaucrat::GradeTooLowException::what() const throw() { return "Grade is too low"; }

// Constructors / Destructors
Bureaucrat::Bureaucrat(const std::string &name, int grade) :m_name(name), m_grade(grade)
{
	if (grade < 1)
	{
		throw Bureaucrat::GradeTooHighException();
	}
	if (grade > 150)
	{
		throw Bureaucrat::GradeTooLowException();
	}
}
Bureaucrat::Bureaucrat(const Bureaucrat &copy) : m_name(copy.m_name), m_grade(copy.m_grade){ }

Bureaucrat::~Bureaucrat() {}

// Operators
std::ostream& operator<<(std::ostream& os, const Bureaucrat& b)
{
	os << b.getName() << ", grade: " << b.getGrade();
	return os;
}

// Getters/Setters
const std::string& Bureaucrat::getName() const { return m_name; }
int Bureaucrat::getGrade() const { return m_grade; }

// Functions
int Bureaucrat::promoteGrade()
{
	if (m_grade <= 1)
		throw Bureaucrat::GradeTooHighException();
	else
		m_grade--;
	return m_grade;
}

int Bureaucrat::demoteGrade()
{
	if (m_grade >= 150)
		throw Bureaucrat::GradeTooLowException();
	else
		m_grade++;
	return m_grade;
}

void Bureaucrat::signForm(AForm& f)
{
	if (f.isSigned())
	{
		std::cout << "form is already signed" << std::endl;
		return;
	}
	try { f.beSigned(*this); }
	catch (std::exception& e)
	{
		std::cerr << m_name << " couldn't sign form because: " << e.what() << "\n";
		return;
	}
		std::cout << m_name << " signed " << f.getName() << std::endl;
}

bool Bureaucrat::executeForm(const AForm& f)
{
	try
	{
		f.execute(*this);
		std::cout << m_name << " executed " << f.getName() << std::endl;
		return true;
	}
	catch (std::exception& e)
	{
		std::cerr << "Cannot execute form because: " << e.what() << "\n";
		return false;
	}
}
