#include "ClapTrap.hpp"

int main() {
	ClapTrap clapTrap("Bob");

	clapTrap.attack("nobody");
	clapTrap.takeDamage(5);
	clapTrap.beRepaired(7);

}
