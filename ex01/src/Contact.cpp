#include "Contact.hpp"

Contact::Contact()
{
	this->set_fname("");
	this->set_lname("");
	this->set_nname("");
	this->set_phone("");
	this->set_secret("");
}

Contact::~Contact()
{
}

const std::string	Contact::get_fname()
{
	return this->fname;
}

const std::string	Contact::get_lname()
{
	return this->lname;
}

const std::string	Contact::get_nname()
{
	return this->nname;
}

const std::string	Contact::get_phone()
{
	return this->phone;
}

const std::string	Contact::get_secret()
{
	return this->secret;
}

void	Contact::set_fname(std::string fname)
{
	this->fname = fname;
}

void	Contact::set_lname(std::string lname)
{
	this->lname = lname;
}

void	Contact::set_nname(std::string nname)
{
	this->nname = nname;
}

void	Contact::set_phone(std::string phone)
{
	this->phone = phone;
}

void	Contact::set_secret(std::string secret)
{
	this->secret = secret;
}
