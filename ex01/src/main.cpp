#include <iostream>
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

int main()
{
	PhoneBook	book;
	std::string	s;

	std::cout << "Welcome to your personnal Phonebook !" << std::endl;
	s = get_input(ACTION);
	while (s != "EXIT")
	{
		if (s == "ADD")
			;
		else if (s == "SEARCH")
			;
		s = get_input(ACTION);
	}
	return 0;
}
