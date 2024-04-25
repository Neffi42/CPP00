#include "ClapTrap.hpp"

int main() {
	ClapTrap clapTrap("Bob");

	clapTrap.attack("nobody");
	clapTrap.status();
	clapTrap.takeDamage(5);
	clapTrap.status();
	clapTrap.beRepaired(7);
	clapTrap.status();
	for (int i = 0; i < 8; i++)
		clapTrap.attack("nobody");
	clapTrap.status();
	clapTrap.attack("nobody");
	clapTrap.takeDamage(66);
	clapTrap.status();
	clapTrap.beRepaired(7);
}
