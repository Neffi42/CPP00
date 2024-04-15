#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
	this->_next = 0;
	this->_len = 0;
}

PhoneBook::~PhoneBook()
{
	for (int i = 0; i < this->_len; i++)
		delete this->_contact[i];
}

void	PhoneBook::_set_contact(Contact *contact)
{
	if (this->_len == 8)
		delete this->_contact[this->_next];
	this->_contact[this->_next] = contact;
	if (this->_next >= 7)
		this->_next = 0;
	else
		this->_next += 1;
	if (this->_len < 8)
		this->_len += 1;
}

std::string	PhoneBook::_format_string(std::string s)
{
	if (s.length() > 10)
		return s.substr(0, 9) + ".";
	return s;
}

void	PhoneBook::_format_print(std::string index, std::string fname, std::string lname, std::string nname)
{
	std::cout.width(10); std::cout << std::right << _format_string(index) << "|";
	std::cout.width(10); std::cout << std::right << _format_string(fname) << "|";
	std::cout.width(10); std::cout << std::right << _format_string(lname) << "|";
	std::cout.width(10); std::cout << std::right << _format_string(nname) << std::endl;
}

std::string	PhoneBook::_get_input(std::string message)
{
	std::string	s;

	std::cout << message << std::endl;
	std::getline(std::cin, s);
	s = s.empty() ? (std::cout << "Error: input cannot be empty" << std::endl, _get_input(message)) : s;
	return s;
}

void	PhoneBook::add()
{
	Contact *contact = new Contact(
	_get_input("Please enter new contact's first name"),
	_get_input("Please enter new contact's last name"),
	_get_input("Please enter new contact's nickname"),
	_get_input("Please enter new contact's phone number"),
	_get_input("Please enter new contact's darkest secret"));
	_set_contact(contact);
}

void	PhoneBook::search()
{
	std::string	index;

	if (this->_len == 0)
	{
		std::cout << ("No contact in the phonebook, please add some\n");
		return;
	}
	_format_print("index", "first name", "last name","nickname");
	for (int i = 0; i < this->_len; i++)
		_format_print(std::to_string(i), this->_contact[i]->get_fname(), this->_contact[i]->get_lname(), this->_contact[i]->get_nname());
	index = _get_input("Please choose the contact that you wish to acces to");
	while (index.length() == 0 || index.length() > 1 || !::isdigit(index[0]) || index[0] >= this->_len + '0')
			index = _get_input("Wrong index, please choose the contact that you wish to acces to");
	std::cout << "First name:\t" << this->_contact[index[0] - '0']->get_fname() << std::endl;
	std::cout << "Last name:\t" << this->_contact[index[0] - '0']->get_lname() << std::endl;
	std::cout << "Nickname:\t" << this->_contact[index[0] - '0']->get_nname() << std::endl;
	std::cout << "Phone number:\t" << this->_contact[index[0] - '0']->get_phone() << std::endl;
	std::cout << "Darkest secret:\t" << this->_contact[index[0] - '0']->get_secret() << std::endl;
}
