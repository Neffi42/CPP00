#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include "Contact.hpp"
#include "PhoneBook.hpp"

#define ACTION "Please enter ADD to create a new contact, SEARCH to look for an existing contact, EXIT to quit the program"

std::string	get_input(std::string message)
{
	std::string	s;

	std::cout << message << std::endl;
	std::getline(std::cin, s);
	s = s.empty() ? (std::cout << "Error: input cannot be empty" << std::endl, get_input(message)) : s;
	return s;
}

void	add(PhoneBook &book)
{
	Contact *contact = new Contact(
	get_input("Please enter new contact's first name"),
	get_input("Please enter new contact's last name"),
	get_input("Please enter new contact's nickname"),
	get_input("Please enter new contact's phone number"),
	get_input("Please enter new contact's darkest secret"));
	book.set_contact(contact);
}

int main()
{
	PhoneBook	book;
	std::string	s;

	std::cout << "Welcome to your personnal Phonebook !" << std::endl;
	while (s != "EXIT")
	{
		if (s == "ADD")
			add(book);
		else if (s == "SEARCH")
			search(book);
		s = get_input(ACTION);
	}
	return 0;
}
