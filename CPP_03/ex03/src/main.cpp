#include "DiamondTrap.hpp"

int main() {
	DiamondTrap diamondTrap("Bob");

	diamondTrap.whoAmI();
	diamondTrap.status();
	diamondTrap.guardGate();
	diamondTrap.highFivesGuys();
	diamondTrap.attack("Handsome Jack");
	return 0;
}
