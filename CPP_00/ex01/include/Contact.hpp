#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>

class Contact
{
private:
	const std::string fname;
	const std::string lname;
	const std::string nname;
	const std::string phone;
	const std::string secret;
public:
	Contact(const std::string &fname, const std::string &lname, const std::string &nname, const std::string &phone, const std::string &secret);
	~Contact();
	const std::string	&getFname();
	const std::string	&getLname();
	const std::string	&getNname();
	const std::string	&getPhone();
	const std::string	&getSecret();
};

#endif
