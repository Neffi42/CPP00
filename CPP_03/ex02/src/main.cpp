#include "FragTrap.hpp"

int main() {
	FragTrap fragTrap("Bob");

	fragTrap.attack("Handsome Jack");
	fragTrap.status();
	fragTrap.takeDamage(5);
	fragTrap.status();
	fragTrap.beRepaired(7);
	fragTrap.status();
	fragTrap.highFivesGuys();
	return 0;
}
