#include "Contact.hpp"

// Constructors/Destructors
Contact::Contact() {}
Contact::Contact(const std::string& f_name, const std::string& l_name, const std::string& n_name,
		const std::string& p_num, const std::string& secret)
		:m_first_name(f_name), m_last_name(l_name), m_nickname(n_name), m_phone_number(p_num), m_secret(secret)
{
}

// Operators
Contact& Contact::operator=(const Contact& contact)
{
	m_first_name = contact.m_first_name;
	m_last_name = contact.m_last_name;
	m_nickname = contact.m_nickname;
	m_phone_number = contact.m_phone_number;
	m_secret = contact.m_secret;
	return *this;
}

// Getters
const std::string& Contact::get_first_name() const { return m_first_name; }
const std::string& Contact::get_last_name() const { return m_last_name; }
const std::string& Contact::get_nickname() const { return m_nickname; }
const std::string& Contact::get_phone_number() const { return m_phone_number; }
const std::string& Contact::get_secret() const { return m_secret; }
