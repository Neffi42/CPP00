#include "Zombie.hpp"

int	main()
{
	Zombie	*zonzon = newZombie("zonzon");

	randomChump("zonzon2");
	zonzon->announce();
	delete zonzon;
	return (0);
}
