#include "ShrubberyCreationForm.hpp"
#include <fstream>

// Constructors/Destructors
ShrubberyCreationForm::	ShrubberyCreationForm(const std::string& target)
	: AForm("Shrubbery Creation", 145, 137), m_target(target){ }
ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm& copy) : AForm(copy), m_target(copy.m_target)  { }

ShrubberyCreationForm::~ShrubberyCreationForm() { }

// Operators
ShrubberyCreationForm& ShrubberyCreationForm::operator=(ShrubberyCreationForm& copy)
{
	m_is_signed = copy.m_is_signed;
	return *this;
}

// Functions
void ShrubberyCreationForm::execute(const Bureaucrat &b) const
{
	canExecuteThrow(b);
	std::ofstream os((m_target + "_shrubbery").c_str(), std::ios_base::app);
	if (!os)
	{
		std::cerr << "could not open file\n";
		return;
	}
	os << "     " << std::endl;
	os << "  |  " << std::endl;
	os << " / \\ " << std::endl;
	os << "/   \\" << std::endl;
	os << "-----" << std::endl;
	os << "  |  " << std::endl;
	os << " ~  ." << std::endl;

	os.close();
}
