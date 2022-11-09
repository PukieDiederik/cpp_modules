#include "Phonebook.h"
#include <iostream>
#include <iomanip>

void Phonebook::print() const
{
	if (m_initialized_contacts == 0)
	{
		std::cout << "No contacts exist in this Phonebook" << std::endl;
		return;
	}
	std::cout << "|     Index|First Name| Last Name|  Nickname|\n";
	std::cout << "+----------+----------+----------+----------+\n";
	for (unsigned int i = 0; i < MAX_CONTACTS && i < m_initialized_contacts; ++i)
	{
		std::cout << "|" << std::setw(10) << i;
		if (m_contacts[i].get_first_name().length() <= 10) // first name
			std::cout << "|" << std::setw(10) << m_contacts[i].get_first_name();
		else
			std::cout << "|" << m_contacts[i].get_first_name().substr(0, 9) << ".";
		if (m_contacts[i].get_last_name().length() <= 10) // last name
			std::cout << "|" << std::setw(10) << m_contacts[i].get_last_name();
		else
			std::cout << "|" << m_contacts[i].get_last_name().substr(0, 9) << ".";
		if (m_contacts[i].get_nickname().length() <= 10) // nickname
			std::cout << "|" << std::setw(10) << m_contacts[i].get_nickname();
		else
			std::cout << "|" << m_contacts[i].get_nickname().substr(0, 9) << ".";
		std::cout << "|\n";
	}
	std::cout << "+----------+----------+----------+----------+" << std::endl;
}

void Phonebook::print_contact(int index) const
{
	if (index < 0 || static_cast<unsigned int>(index) >= m_initialized_contacts)
	{
		std::cout << "Invalid index: " << index << std::endl;
		return;
	}
	std::cout << "First name   : " << m_contacts[index].get_first_name() << "\n";
	std::cout << "Last name    : " << m_contacts[index].get_last_name() << "\n";
	std::cout << "Nickname     : " << m_contacts[index].get_nickname() << "\n";
	std::cout << "Phone number : " << m_contacts[index].get_phone_number() << "\n";
	std::cout << "Secret       : " << m_contacts[index].get_secret() << std::endl;
}

void Phonebook::add_contact(const std::string& f_name, const std::string& l_name, const std::string& n_name,
				 const std::string& p_num, const std::string& secret)
{
	m_contacts[m_cur_contact_index] = Contact(f_name, l_name, n_name, p_num, secret);
	m_cur_contact_index = (m_cur_contact_index + 1) % MAX_CONTACTS;
	if (m_initialized_contacts < MAX_CONTACTS)
		++m_initialized_contacts;
}

// Getters/Setters
unsigned int Phonebook::get_contact_amount() const { return m_initialized_contacts;}
