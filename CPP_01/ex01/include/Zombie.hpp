#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>

class Zombie {
private:
	std::string name;
public:
	Zombie();
	Zombie(const std::string &name);
	~Zombie();
	void setName(const std::string &name);
	void announce();
};

Zombie	*zombieHorde(int N, std::string name);

#endif
