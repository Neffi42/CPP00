#include "Zombie.hpp"

Zombie	*newZombie(std::string name)
{
	Zombie *zonzon;

	try {
		zonzon = new Zombie(name);
	}
	catch (const std::exception& e) {
		std::cerr << e.what() << '\n';
		return NULL;
	}
	return zonzon;
}
