#include "ClapTrap.hpp"

ClapTrap::ClapTrap() {
	this->name = "Default";
	this->hp = 0;
	this->energy = 0;
	this->damage = 0;
	std::cout << "ClapTrap " << this->name << " has been created!" << std::endl;
}

ClapTrap::ClapTrap(const std::string &name): name(name), hp(10), energy(10), damage(0) {
	this->name = name;
	this->hp = 10;
	this->energy = 10;
	this->damage = 0;
	std::cout << "ClapTrap " << this->name << " has been created!" << std::endl;
}

ClapTrap::~ClapTrap() {
	std::cout << "ClapTrap " << this->name << " has been destroyed!" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other) {
	*this = other;
	std::cout << "ClapTrap " << this->name << " has been copied!" << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other) {
	if (this != &other)
	{
		this->name = other.name;
		this->hp = other.hp;
		this->energy = other.energy;
		this->damage = other.damage;
	}
	std::cout << "ClapTrap " << this->name << " has been assigned!" << std::endl;
	return *this;
}

void ClapTrap::attack(const std::string& target) {
	if (!this->checkHp())
		return;
	if (!this->checkEnergy())
		return;
	std::cout << "ClapTrap " << this->name << " attacks " << target << ", causing " << this->damage << " points of damage!" << std::endl;
	if (this->energy > 0)
		this->energy--;
}

void ClapTrap::takeDamage(unsigned int amount) {
	if (!this->checkHp())
		return;
	std::cout << "ClapTrap " << this->name << " takes " << amount << " points of damage!" << std::endl;
	this->hp = (this->hp <= amount) ? 0 : this->hp - amount;
}

void ClapTrap::beRepaired(unsigned int amount) {
	if (!this->checkHp())
		return;
	if (!this->checkEnergy())
		return;
	std::cout << "ClapTrap " << this->name << " repairs " << amount << " points of damage!" << std::endl;
	this->hp += amount;
	if (this->energy > 0)
		this->energy--;
}

bool ClapTrap::checkHp() const {
	if (this->hp > 0)
		return true;
	std::cout << "ClapTrap " << this->name << " is dead" << std::endl;
	return false;
}


bool ClapTrap::checkEnergy() const {
	if (this->energy > 0)
		return true;
	std::cout << "ClapTrap " << this->name << " has no energy" << std::endl;
	return false;
}

void ClapTrap::status() const {
	std::cout << "ClapTrap " << this->name << " has " << this->hp << " health points and " << this->energy << " energy points" << std::endl;
}
