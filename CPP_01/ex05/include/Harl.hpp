#ifndef HARL_HPP
# define HARL_HPP

# include <iostream>
# include <string>
# include <map>

class Harl {
private:
	std::map<std::string, void (Harl::*)()> levels;
	void debug();
	void info();
	void warning();
	void error();
public:
	Harl();
	~Harl();
	void complain(const std::string &level);
};

#endif
