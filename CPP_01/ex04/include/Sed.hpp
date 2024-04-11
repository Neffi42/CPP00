#ifndef SED_HPP
# define SED_HPP

# include <iostream>
# include <fstream>
# include <string>

class Sed {
private:
	std::ifstream	_in;
	std::ofstream	_out;
	std::string		_name;
	std::string		_find;
	std::string		_replace;
public:
	Sed(std::string name, std::string find, std::string replace);
	~Sed();
	void copyFile();
	void replaceAll(std::string &line);
};

#endif
