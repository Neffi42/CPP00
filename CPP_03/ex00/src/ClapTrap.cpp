#include "ClapTrap.hpp"

ClapTrap::ClapTrap(const std::string &name): name(name), hp(10), energy(10), damage(0) {}

ClapTrap::~ClapTrap() {}

ClapTrap::ClapTrap(const ClapTrap &other) {
	*this = other;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other) {
	if (this != &other)
	{
		this->name = other.name;
		this->hp = other.hp;
		this->energy = other.energy;
		this->damage = other.damage;
	}
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

bool ClapTrap::checkHp()
{
	if (this->hp > 0)
		return true;
	std::cout << "ClapTrap " << this->name << " is dead" << std::endl;
	return false;
}


bool ClapTrap::checkEnergy()
{
	if (this->energy > 0)
		return true;
	std::cout << "ClapTrap " << this->name << " has no energy" << std::endl;
	return false;
}

void ClapTrap::status() {
	std::cout << "ClapTrap " << this->name << " has " << this->hp << " health points and " << this->energy << " energy points" << std::endl;
}
