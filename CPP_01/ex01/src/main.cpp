#include "Zombie.hpp"

int main() {
	int		nb = 5;

	Zombie	*zombies = zombieHorde(nb, "zonzon");
	if (!zombies)
		return 1;
	for (int i = 0; i < nb; i++)
		zombies[i].announce();
	delete [] zombies;
}
