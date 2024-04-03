#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>

class Contact
{
private:
	const std::string _fname;
	const std::string _lname;
	const std::string _nname;
	const std::string _phone;
	const std::string _secret;
public:
	Contact(std::string fname, std::string lname, std::string nname, std::string phone, std::string secret);
	~Contact();
	const std::string	&get_fname();
	const std::string	&get_lname();
	const std::string	&get_nname();
	const std::string	&get_phone();
	const std::string	&get_secret();
};

#endif
