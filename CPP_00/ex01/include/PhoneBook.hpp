# ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iostream>
# include <string>
# include "Contact.hpp"

class PhoneBook
{
private:
	Contact		*_contact[8];
	int			_next;
	int			_len;
	void		_format_print(std::string index, std::string fname, std::string lname, std::string nname);
	std::string	_format_string(std::string s);
	std::string	_get_input(std::string message);
	void		_set_contact(Contact *contact);
public:
	PhoneBook();
	~PhoneBook();
	void	search();
	void	add();
};

#endif
