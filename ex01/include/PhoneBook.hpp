# ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"

class PhoneBook
{
private:
	Contact	contact[8];
	int		next;
	int		len;
public:
	PhoneBook();
	~PhoneBook();
	Contact	get_contact(int index);
	int		get_next();
	int		get_len();
	void	set_contact(std::string fname, std::string lname, std::string phone, std::string secret);
	void	set_next(int next);
	void	set_len(int len);
};

#endif
