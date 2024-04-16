# ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iostream>
# include <string>
# include <sstream>
# include <cstdlib>
# include "Contact.hpp"

class PhoneBook
{
private:
	Contact		*contact[8];
	int			next;
	int			len;
	void		formatPrint(std::string index, std::string fname, std::string lname, std::string nname);
	std::string	formatString(std::string s);
	std::string	getInput(std::string message);
	void		setContact(Contact *contact);
	std::string	intToString(int n);
	bool		checkInput(std::string s);
public:
	PhoneBook();
	~PhoneBook();
	void	search();
	int	add();
};

#endif
