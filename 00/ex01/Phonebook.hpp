// A class to store up to 8 contacts
#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include "Contact.hpp"

#define MAX_CONTACTS 8

class Phonebook {
private:
	Contact m_contacts[MAX_CONTACTS];
	unsigned int m_initialized_contacts; // How many contacts have been initialized
	unsigned int m_cur_contact_index; // What the next index to be modified is
public:
	// Constructors
	Phonebook();

	// Member functions
	void print() const;
	void print_contact(int index) const;
	void add_contact(const std::string& f_name, const std::string& l_name, const std::string& n_name,
					 const std::string& p_num, const std::string& secret);

	// Getters/Setters
	unsigned int get_contact_amount() const;
};


#endif
