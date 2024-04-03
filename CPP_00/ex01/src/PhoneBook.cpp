#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
	set_next(0);
	set_len(0);
}

PhoneBook::~PhoneBook()
{
	for (int i = 0; i < this->_len; i++)
		delete this->_contact[i];
}

Contact		*PhoneBook::get_contact(int index)
{
	return this->_contact[index];
}

int	PhoneBook::get_next()
{
	return this->_next;
}

int	PhoneBook::get_len()
{
	return this->_len;
}

void	PhoneBook::set_contact(Contact *contact)
{
	if (get_len() == 8)
		delete this->_contact[get_next()];
	this->_contact[get_next()] = contact;
	if (get_next() >= 7)
		set_next(0);
	else
		set_next(get_next() + 1);
	if (get_len() < 8)
		set_len(get_len() + 1);
}

void	PhoneBook::set_next(int next)
{
	this->_next = next;
}

void	PhoneBook::set_len(int len)
{
	this->_len = len;
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
	set_contact(contact);
}

void	PhoneBook::search()
{
	int			len = get_len();
	std::string	index;

	if (len == 0)
	{
		std::cout << ("No contact in the phonebook, please add some\n");
		return;
	}
	_format_print("index", "first name", "last name","nickname");
	for (int i = 0; i < len; i++)
		_format_print(std::to_string(i), get_contact(i)->get_fname(), get_contact(i)->get_lname(), get_contact(i)->get_nname());
	index = _get_input("Please choose the contact that you wish to acces to");
	while (index.length() == 0 || index.length() > 1 || !::isdigit(index[0]) || index[0] >= len + '0')
			index = _get_input("Wrong index, please choose the contact that you wish to acces to");
	std::cout << "First name:\t" << get_contact(index[0] - '0')->get_fname() << std::endl;
	std::cout << "Last name:\t" << get_contact(index[0] - '0')->get_lname() << std::endl;
	std::cout << "Nickname:\t" << get_contact(index[0] - '0')->get_nname() << std::endl;
	std::cout << "Phone number:\t" << get_contact(index[0] - '0')->get_phone() << std::endl;
	std::cout << "Darkest secret:\t" << get_contact(index[0] - '0')->get_secret() << std::endl;
}
