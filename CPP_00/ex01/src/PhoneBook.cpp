#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
	this->next = 0;
	this->len = 0;
}

PhoneBook::~PhoneBook()
{
	for (int i = 0; i < this->len; i++)
		delete this->contact[i];
}

void	PhoneBook::setContact(Contact *contact)
{
	if (this->len == 8)
		delete this->contact[this->next];
	this->contact[this->next] = contact;
	if (this->next >= 7)
		this->next = 0;
	else
		this->next += 1;
	if (this->len < 8)
		this->len += 1;
}

std::string	PhoneBook::formatString(std::string s)
{
	if (s.length() > 10)
		return s.substr(0, 9) + ".";
	return s;
}

void	PhoneBook::formatPrint(std::string index, std::string fname, std::string lname, std::string nname)
{
	std::cout.width(10); std::cout << std::right << formatString(index) << "|";
	std::cout.width(10); std::cout << std::right << formatString(fname) << "|";
	std::cout.width(10); std::cout << std::right << formatString(lname) << "|";
	std::cout.width(10); std::cout << std::right << formatString(nname) << std::endl;
}

bool	PhoneBook::checkInput(std::string s)
{
	if (s.empty())
	{
		std::cout << "Error: input cannot be empty" << std::endl;
		return false;
	}
	for (size_t i = 0; s[i]; i++)
	{
		if (!isalnum(s[i]))
		{
			std::cout << "Error: input can only contain alnum chars" << std::endl;
			return false;
		}
	}
	return true;
}

std::string	PhoneBook::getInput(std::string message)
{
	std::string	s;

	if (!std::cin.eof())
		std::cout << message << std::endl;
	std::getline(std::cin, s);
	if (std::cin.eof())
		s.clear();
	else
		s = this->checkInput(s) ? s : getInput(message);
	return s;
}

int	PhoneBook::add()
{
	Contact	*contact;

	try {
		contact = new Contact(
		getInput("Please enter new contact's first name"),
		getInput("Please enter new contact's last name"),
		getInput("Please enter new contact's nickname"),
		getInput("Please enter new contact's phone number"),
		getInput("Please enter new contact's darkest secret")
		);
	}
	catch(const std::exception& e) {
		std::cerr << e.what() << '\n';
		return 1;
	}
	setContact(contact);
	return 0;
}

std::string	PhoneBook::intToString(int n)
{
	std::ostringstream ss;
	ss << n;
	return (ss.str());
}

void	PhoneBook::search()
{
	std::string	index;

	if (this->len == 0)
	{
		std::cout << ("No contact in the phonebook, please add some\n");
		return;
	}
	formatPrint("index", "first name", "last name","nickname");
	for (int i = 0; i < this->len; i++)
		formatPrint(this->intToString(i), this->contact[i]->getFname(), this->contact[i]->getLname(), this->contact[i]->getNname());
	index = getInput("Please choose the contact that you wish to acces to");
	if (std::cin.eof())
		return ;
	while (!std::cin.eof() && (index.length() != 1 || !isdigit(index[0]) || index[0] >= this->len + '0'))
		index = getInput("Wrong index, please choose the contact that you wish to acces to");
	if (std::cin.eof())
		return ;
	std::cout << "First name:\t" << this->contact[index[0] - '0']->getFname() << std::endl;
	std::cout << "Last name:\t" << this->contact[index[0] - '0']->getLname() << std::endl;
	std::cout << "Nickname:\t" << this->contact[index[0] - '0']->getNname() << std::endl;
	std::cout << "Phone number:\t" << this->contact[index[0] - '0']->getPhone() << std::endl;
	std::cout << "Darkest secret:\t" << this->contact[index[0] - '0']->getSecret() << std::endl;
}
