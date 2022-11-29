#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::GradeTooHighException::GradeTooHighException() {}
Form::GradeTooHighException::GradeTooHighException(const Form::GradeTooHighException& copy)
{
	*this = copy;
}
Form::GradeTooHighException::~GradeTooHighException() throw() {}

Form::GradeTooHighException& Form::GradeTooHighException::operator=(
		const Form::GradeTooHighException& copy
)
{
	std::exception::operator=(copy);
	return *this;
}

const char* Form::GradeTooHighException::what() const throw() { return "Form grade too high"; }

//  Grade too low
Form::GradeTooLowException::GradeTooLowException() { }
Form::GradeTooLowException::GradeTooLowException(const Form::GradeTooLowException& copy)
{
	*this = copy;
}
Form::GradeTooLowException::~GradeTooLowException() throw(){}

Form::GradeTooLowException& Form::GradeTooLowException::operator=(
		const Form::GradeTooLowException& copy
)
{
	std::exception::operator=(copy);
	return *this;
}

const char* Form::GradeTooLowException::what() const throw() { return "Form grade too low"; }

// Constructors/Destructors
Form::Form(const std::string& name, int sign_grade, int exec_grade) : m_name(name), m_is_signed(false),
																	  m_req_sign_grade(sign_grade),
																	  m_req_execute_grade(exec_grade)
{
	 if (sign_grade > 150 || exec_grade > 150)
		 throw Form::GradeTooLowException();
	 if (sign_grade < 1 || exec_grade < 1)
		 throw Form::GradeTooHighException();
}
Form::Form(const Form &copy) :m_name(copy.m_name), m_is_signed(copy.m_is_signed),
							  m_req_sign_grade(copy.m_req_sign_grade), m_req_execute_grade(copy.m_req_execute_grade) { }


// operators
std::ostream& operator<<(std::ostream& os, const Form& form)
{
	os << "Form: " << form.getName() << ", sign grade: " << form.getSignGrade()
	   << ", exec grade: " << form.getExecGrade() << ", is signed: " << std::boolalpha << form.isSigned();
	return os;
}

// Getters/Setters
const std::string& Form::getName() const { return m_name; }
int Form::getSignGrade() const { return m_req_sign_grade; }
int Form::getExecGrade() const { return m_req_execute_grade; }
bool Form::isSigned() const { return m_is_signed; }

// Functions
void Form::beSigned(const Bureaucrat &b)
{
	if (b.getGrade() > m_req_sign_grade)
		throw Form::GradeTooLowException();
	m_is_signed = true;
}

