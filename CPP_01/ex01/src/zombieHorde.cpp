#include "Zombie.hpp"

Zombie	*zombieHorde(int N, std::string name) {
	Zombie	*zombies;

	try {
		zombies = new Zombie[N];
	}
	catch (const std::exception& e) {
		std::cerr << e.what() << '\n';
		return NULL;
	}

	for (int i = 0; i < N; i++)
		zombies[i].setName(name);
	return (zombies);
}
