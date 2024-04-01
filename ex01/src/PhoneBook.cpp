#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
	this->set_next(0);
	this->set_len(0);
}

PhoneBook::~PhoneBook()
{
}

Contact		*PhoneBook::get_contact(int index)
{
	return &this->contact[index];
}

int	PhoneBook::get_next()
{
	return this->next;
}

int	PhoneBook::get_len()
{
	return this->len;
}

void	PhoneBook::set_contact(std::string fname, std::string lname, std::string nname, std::string phone, std::string secret)
{
	Contact	*new_contact = get_contact(this->next);

	new_contact->set_fname(fname);
	new_contact->set_lname(lname);
	new_contact->set_nname(nname);
	new_contact->set_phone(phone);
	new_contact->set_secret(secret);
	if (this->next >= 7)
		this->set_next(0);
	else
		this->set_next(this->next + 1);
	if (this->len < 8)
		this->set_len(this->len + 1);
}

void	PhoneBook::set_next(int next)
{
	this->next = next;
}

void	PhoneBook::set_len(int len)
{
	this->len = len;
}
