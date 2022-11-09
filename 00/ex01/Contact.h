#ifndef CONTACT_H
#define CONTACT_H

#include <string>

class Contact {
private:
	std::string m_first_name;
	std::string m_last_name;
	std::string m_nickname;
	std::string m_phone_number;
	std::string m_secret;

public:
	// Constructors
	Contact() {};
	Contact(const std::string& f_name, const std::string& l_name, const std::string& n_name,
			const std::string& p_num, const std::string& secret)
		:m_first_name(f_name), m_last_name(l_name), m_nickname(n_name), m_phone_number(p_num), m_secret(secret)
	{
	}

	// Operators
	Contact& operator=(const Contact& contact);

	// Getter/Setters
	const std::string& get_first_name () const;
	const std::string& get_last_name () const;
	const std::string& get_nickname () const;
	const std::string& get_phone_number () const;
	const std::string& get_secret () const;
};


#endif
