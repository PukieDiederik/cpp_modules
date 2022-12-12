#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::GradeTooHighException::GradeTooHighException() {}
AForm::GradeTooHighException::GradeTooHighException(const AForm::GradeTooHighException& copy)
{
	*this = copy;
}
AForm::GradeTooHighException::~GradeTooHighException() throw() {}

AForm::GradeTooHighException& AForm::GradeTooHighException::operator=(
		const AForm::GradeTooHighException& copy
)
{
	std::exception::operator=(copy);
	return *this;
}

const char* AForm::GradeTooHighException::what() const throw() { return "Form grade too high"; }

//  Grade too low
AForm::GradeTooLowException::GradeTooLowException() { }
AForm::GradeTooLowException::GradeTooLowException(const AForm::GradeTooLowException& copy)
{
	*this = copy;
}
AForm::GradeTooLowException::~GradeTooLowException() throw(){}

AForm::GradeTooLowException& AForm::GradeTooLowException::operator=(
		const AForm::GradeTooLowException& copy
)
{
	std::exception::operator=(copy);
	return *this;
}

const char* AForm::GradeTooLowException::what() const throw() { return "Form grade too low"; }

// Constructors/Destructors
AForm::AForm(const std::string& name, int sign_grade, int exec_grade) : m_name(name), m_is_signed(false),
																	  m_req_sign_grade(sign_grade),
																	  m_req_execute_grade(exec_grade)
{
	 if (sign_grade > 150 || exec_grade > 150)
		 throw AForm::GradeTooLowException();
	 if (sign_grade < 1 || exec_grade < 1)
		 throw AForm::GradeTooHighException();
}
AForm::AForm(const AForm &copy) :m_name(copy.m_name), m_is_signed(copy.m_is_signed),
							  m_req_sign_grade(copy.m_req_sign_grade), m_req_execute_grade(copy.m_req_execute_grade) { }

AForm::~AForm() { }


// operators
std::ostream& operator<<(std::ostream& os, const AForm& form)
{
	os << "Form: " << form.getName() << ", sign grade: " << form.getSignGrade()
	   << ", exec grade: " << form.getExecGrade() << ", is signed: " << std::boolalpha << form.isSigned();
	return os;
}

// Getters/Setters
const std::string& AForm::getName() const { return m_name; }
int AForm::getSignGrade() const { return m_req_sign_grade; }
int AForm::getExecGrade() const { return m_req_execute_grade; }
bool AForm::isSigned() const { return m_is_signed; }

// Functions
void AForm::beSigned(const Bureaucrat &b)
{
	if (b.getGrade() > m_req_sign_grade)
		throw AForm::GradeTooLowException();
	m_is_signed = true;
}

void AForm::canExecuteThrow(const Bureaucrat& b) const
{
	if (!m_is_signed)
		throw std::runtime_error("Form is not signed, and can therefor not be executed");
	else if (b.getGrade() > m_req_execute_grade)
		throw AForm::GradeTooLowException();
}
