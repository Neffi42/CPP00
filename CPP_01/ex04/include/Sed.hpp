#ifndef SED_HPP
# define SED_HPP

# include <iostream>
# include <fstream>
# include <string>
# include <cstring>

class Sed {
private:
	std::ifstream	in;
	std::ofstream	out;
	std::string		find;
	std::string		replace;
	void 			replaceAll(std::string &line);
public:
	Sed(std::string name, const std::string &find, const std::string &replace);
	~Sed();
	void copyFile();
};

#endif
