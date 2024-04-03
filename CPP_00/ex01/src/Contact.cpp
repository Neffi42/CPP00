#include "Contact.hpp"

Contact::Contact(std::string fname, std::string lname, std::string nname, std::string phone, std::string secret)
: _fname(fname), _lname(lname), _nname(nname), _phone(phone), _secret(secret){}

Contact::~Contact()
{
}

const std::string	&Contact::get_fname()
{
	return this->_fname;
}

const std::string	&Contact::get_lname()
{
	return this->_lname;
}

const std::string	&Contact::get_nname()
{
	return this->_nname;
}

const std::string	&Contact::get_phone()
{
	return this->_phone;
}

const std::string	&Contact::get_secret()
{
	return this->_secret;
}
