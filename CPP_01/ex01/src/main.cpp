#include "Zombie.hpp"

int main() {
	int		nb = 5;

	Zombie	*zombies = zombieHorde(nb, "zonzon");
	for (int i = 0; i < nb; i++)
		zombies[i].announce();
	delete [] zombies;
}
