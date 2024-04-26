#include "ScavTrap.hpp"

int main() {
	ScavTrap scavTrap("Bob");

	scavTrap.attack("Handsome Jack");
	scavTrap.status();
	scavTrap.takeDamage(5);
	scavTrap.status();
	scavTrap.beRepaired(7);
	scavTrap.status();
	scavTrap.guardGate();
	return 0;
}
