#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(const std::string &name): ClapTrap(name + "_clap_name"), FragTrap(), ScavTrap() {
	this->name = name;
	this->hp = FragTrap::hp;
	this->energy = ScavTrap::energy;
	this->damage = FragTrap::damage;
	std::cout << "DiamondTrap " << this->name << " has been created!" << std::endl;
}

DiamondTrap::~DiamondTrap() {
	std::cout << "DiamondTrap " << this->name << " has been destroyed!" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &other): ClapTrap(other), FragTrap(other), ScavTrap(other) {
	*this = other;
	std::cout << "DiamondTrap " << this->name << " has been copied!" << std::endl;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &other) {
	if (this != &other)
	{
		this->name = other.name;
		this->hp = other.hp;
		this->energy = other.energy;
		this->damage = other.damage;
		ClapTrap::name = other.name + "_clap_name";
	}
	std::cout << "DiamondTrap " << this->name << " has been assigned!" << std::endl;
	return *this;
}

void DiamondTrap::whoAmI() const {
	std::cout << "DiamondTrap is " << this->name << " and " << ClapTrap::name << " at the same time!" << std::endl;
}
