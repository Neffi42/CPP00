#include "Contact.hpp"

Contact::Contact(const std::string &fname, const std::string &lname, const std::string &nname, const std::string &phone, const std::string &secret)
: fname(fname), lname(lname), nname(nname), phone(phone), secret(secret){}

Contact::~Contact()
{
}

const std::string	&Contact::getFname()
{
	return this->fname;
}

const std::string	&Contact::getLname()
{
	return this->lname;
}

const std::string	&Contact::getNname()
{
	return this->nname;
}

const std::string	&Contact::getPhone()
{
	return this->phone;
}

const std::string	&Contact::getSecret()
{
	return this->secret;
}
