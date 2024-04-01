#include <iostream>
#include <iomanip>
#include <string>
#include "Contact.hpp"
#include "PhoneBook.hpp"

#define ACTION "Please enter ADD to create a new contact, SEARCH to look for an existing contact, EXIT to quit the program"

std::string trim(std::string s)
{
	s.erase(std::remove_if(s.begin(), s.end(), ::isspace), s.end());
	return s;
}

std::string	get_input(std::string message)
{
	std::string	s;

	std::cout << message << std::endl;
	std::getline(std::cin, s);
	return trim(s);
}

void	add(PhoneBook *book)
{
	Contact new_contact;

	while (new_contact.get_fname().empty())
		new_contact.set_fname(get_input("Please enter new contact's first name"));
	while (new_contact.get_lname().empty())
		new_contact.set_lname(get_input("Please enter new contact's last name"));
	while (new_contact.get_nname().empty())
		new_contact.set_nname(get_input("Please enter new contact's nickname"));
	while (new_contact.get_phone().empty())
		new_contact.set_phone(get_input("Please enter new contact's phone"));
	while (new_contact.get_secret().empty())
		new_contact.set_secret(get_input("Please enter new contact's darkest secret"));
	book->set_contact(new_contact.get_fname(), new_contact.get_lname(), new_contact.get_nname(), new_contact.get_phone(), new_contact.get_secret());
	system("clear");
}

std::string	format_string(std::string s)
{
	if (s.length() > 10)
		return s.substr(0, 9) + ".";
	return s;
}

void	format_print(std::string index, std::string fname, std::string lname, std::string nname)
{
	std::cout.width(10); std::cout << std::right << format_string(index) << "|";
	std::cout.width(10); std::cout << std::right << format_string(fname) << "|";
	std::cout.width(10); std::cout << std::right << format_string(lname) << "|";
	std::cout.width(10); std::cout << std::right << format_string(nname) << std::endl;
}

void	search(PhoneBook book)
{
	int			len = book.get_len();
	Contact		*tmp;
	std::string	index = "";

	if (len == 0)
	{
		std::cout << "No contact in the phonebook, please add some" << std::endl;
		return;
	}
	format_print("index", "first name", "last name","nickname");
	for (int i = 0; i < len; i++)
	{
		tmp = book.get_contact(i);
		index = "0";
		index[0] += i;
		format_print(index, tmp->get_fname(), tmp->get_lname(), tmp->get_nname());
	}
	system("clear");
}

int main()
{
	PhoneBook	book;
	std::string	s;

	system("clear");
	std::cout << "Welcome to your personnal Phonebook !" << std::endl;
	s = get_input(ACTION);
	while (s != "EXIT")
	{
		if (s == "ADD")
			add(&book);
		else if (s == "SEARCH")
			search(book);
		else
			system("clear");
		s = get_input(ACTION);
	}
	return 0;
}
