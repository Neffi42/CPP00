#include "ScavTrap.hpp"

ScavTrap::ScavTrap(const std::string &name) {
	this->name = name;
	this->hp = 100;
	this->energy = 50;
	this->damage = 20;
	std::cout << "ScavTrap " << this->name << " has been created!" << std::endl;
}

ScavTrap::~ScavTrap() {
	std::cout << "ScavTrap " << this->name << " has been destroyed!" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &other) {
	*this = other;
	std::cout << "ScavTrap " << this->name << " has been copied!" << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &other) {
	if (this != &other)
	{
		this->name = other.name;
		this->hp = other.hp;
		this->energy = other.energy;
		this->damage = other.damage;
	}
	std::cout << "ScavTrap " << this->name << " has been assigned!" << std::endl;
	return *this;
}

void ScavTrap::guardGate() const {
	std::cout << "ScavTrap " << this->name << " is gatekeeping!" << std::endl;
}

void ScavTrap::attack(const std::string& target) {
	if (!this->checkHp())
		return;
	if (!this->checkEnergy())
		return;
	std::cout << "ScavTrap " << this->name << " attacks " << target << ", causing " << this->damage << " points of damage!" << std::endl;
	if (this->energy > 0)
		this->energy--;
}
