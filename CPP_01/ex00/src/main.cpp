#include "Zombie.hpp"

int	main() {
	Zombie	*zonzon = newZombie("zonzon");
	if (!zonzon)
		return 1;

	randomChump("zonzon2");
	zonzon->announce();
	delete zonzon;
	return (0);
}
