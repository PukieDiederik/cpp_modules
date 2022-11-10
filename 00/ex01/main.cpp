#include "Contact.hpp"
#include "Phonebook.hpp"
#include <ios>
#include <iostream>
#include <limits>

void add_user(Phonebook& pb)
{
	std::string f_name;
	std::string l_name;
	std::string nickname;
	std::string phone;
	std::string secret;

	//get all input
	std::cout << "First name    : " << std::flush;
	std::getline(std::cin, f_name);
	std::cout << "Last name     : " << std::flush;
	std::getline(std::cin, l_name);
	std::cout << "Nickname      : " << std::flush;
	std::getline(std::cin, nickname);
	std::cout << "Phone number  : " << std::flush;
	std::getline(std::cin, phone);
	std::cout << "Darkest secret: " << std::flush;
	std::getline(std::cin, secret);

	//add the contact to the phonebook
	pb.add_contact(f_name, l_name, nickname, phone, secret);
	std::cout << "Contact succesfully added" << std::endl;
}

void search(Phonebook& pb)
{
	//print all the contacts
	pb.print();
	if (pb.get_contact_amount() == 0)
		return;

	int i;
	std::cout << "Type the index of the contact you would like to view: " << std::flush;
	std::cin >> i;
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	if (std::cin.fail())
	{
		std::cerr << "error with reading index\n";
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		return;
	}
	pb.print_contact(i);
}

int main()
{
	Phonebook pb;

	std::string input;
	std::cout << "Possible commands are: ADD SEARCH EXIT" << std::endl;
	while (true)
	{
		try
		{
			std::getline(std::cin, input);
			if (input == "EXIT")
				return (0);
			else if (input == "ADD")
				add_user(pb);
			else if (input == "SEARCH")
				search(pb);
			else
				std::cout << "Unknown command: " << input << std::endl;
		}
		catch (std::exception& e)
		{
			std::cerr << "Exception occured: " << e.what() << "\n";
			return (1);
		}
	}
}