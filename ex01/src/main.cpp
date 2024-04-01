#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include "Contact.hpp"
#include "PhoneBook.hpp"

#define ACTION "Please enter ADD to create a new contact, SEARCH to look for an existing contact, EXIT to quit the program"
#define CONTINUE "Please press enter to continue"

std::string trim(std::string s)
{
	for (size_t i = 0; s[i]; i++)
	{
		if (isspace(s[i]))
			s.erase(i--, 1);
		else
			break;
	}
	for (size_t i = s.length() - 1; i > 0; i--)
	{
		if (isspace(s[i]))
			s.erase(i++, 1);
		else
			break;
	}
	return s;
}

std::string	get_input(std::string message)
{
	std::string	s;

	std::cout << message << std::endl;
	std::getline(std::cin, s);
	return trim(s);
}

void	input_clear(std::string message)
{
	get_input(message);
	system("clear");
}

void	add(PhoneBook *book)
{
	Contact new_contact;

	while (new_contact.get_fname().length() == 0)
		new_contact.set_fname(get_input("Please enter new contact's first name"));
	while (new_contact.get_lname().length() == 0)
		new_contact.set_lname(get_input("Please enter new contact's last name"));
	while (new_contact.get_nname().length() == 0)
		new_contact.set_nname(get_input("Please enter new contact's nickname"));
	while (new_contact.get_phone().length() == 0)
		new_contact.set_phone(get_input("Please enter new contact's phone number"));
	while (new_contact.get_secret().length() == 0)
		new_contact.set_secret(get_input("Please enter new contact's darkest secret"));
	book->set_contact(new_contact.get_fname(), new_contact.get_lname(), new_contact.get_nname(), new_contact.get_phone(), new_contact.get_secret());
	input_clear(CONTINUE);
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
		return input_clear("No contact in the phonebook, please add some\n" CONTINUE);
	format_print("index", "first name", "last name","nickname");
	for (int i = 0; i < len; i++)
	{
		tmp = book.get_contact(i);
		index = "0";
		index[0] += i;
		format_print(index, tmp->get_fname(), tmp->get_lname(), tmp->get_nname());
	}
	index = get_input("Please choose the contact that you wish to acces to");
	while (index.length() == 0 || index.length() > 1 || !::isdigit(index[0]) || index[0] >= len + '0')
			index = get_input("Wrong index, please choose the contact that you wish to acces to");
	system("clear");
	std::cout << "First name:\t" << book.get_contact(index[0] - '0')->get_fname() << std::endl;
	std::cout << "Last name:\t" << book.get_contact(index[0] - '0')->get_lname() << std::endl;
	std::cout << "Nickname:\t" << book.get_contact(index[0] - '0')->get_nname() << std::endl;
	std::cout << "Phone number:\t" << book.get_contact(index[0] - '0')->get_phone() << std::endl;
	std::cout << "Darkest secret:\t" << book.get_contact(index[0] - '0')->get_secret() << std::endl;
	input_clear(CONTINUE);
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
