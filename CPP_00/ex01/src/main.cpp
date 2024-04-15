#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include "Contact.hpp"
#include "PhoneBook.hpp"

int main()
{
	PhoneBook	book;
	std::string	s;

	std::cout << "Welcome to your personnal Phonebook !" << std::endl;
	while (s != "EXIT")
	{
		if (s == "ADD")
		{
			if (book.add())
				return 1;
		}
		else if (s == "SEARCH")
			book.search();
		if (!std::cin.eof())
			std::cout << "Please enter ADD to create a new contact, SEARCH to look for an existing contact, EXIT to quit the program" << std::endl;
		std::getline(std::cin, s);
		if (std::cin.eof())
			return 0;
	}
	return 0;
}
