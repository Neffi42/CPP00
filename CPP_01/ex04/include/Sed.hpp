#ifndef SED_HPP
# define SED_HPP

# include <iostream>
# include <fstream>
# include <string>
# include <cstring>

class Sed {
private:
	std::ifstream	_in;
	std::ofstream	_out;
	std::string		_find;
	std::string		_replace;
	void 			_replaceAll(std::string &line);
public:
	Sed(char *name, std::string find, std::string replace);
	~Sed();
	void copyFile();
};

#endif
