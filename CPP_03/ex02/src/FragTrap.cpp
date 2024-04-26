#include "FragTrap.hpp"

FragTrap::FragTrap(const std::string &name) {
	this->name = name;
	this->hp = 100;
	this->energy = 100;
	this->damage = 30;
	std::cout << "FragTrap " << this->name << " has been created!" << std::endl;
}

FragTrap::~FragTrap() {
	std::cout << "FragTrap " << this->name << " has been destroyed!" << std::endl;
}

FragTrap::FragTrap(const FragTrap &other) {
	*this = other;
	std::cout << "FragTrap " << this->name << " has been copied!" << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &other) {
	if (this != &other)
	{
		this->name = other.name;
		this->hp = other.hp;
		this->energy = other.energy;
		this->damage = other.damage;
	}
	std::cout << "FragTrap " << this->name << " has been assigned!" << std::endl;
	return *this;
}

void FragTrap::highFivesGuys() const {
	std::cout << "FragTrap " << this->name << " ask for a high five! Nobody answers..." << std::endl;
}
