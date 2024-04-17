#include "HumanB.hpp"

HumanB::HumanB(const std::string &name): name(name), weapon("") {}

HumanB::~HumanB() {}

void HumanB::attack() {
	if (this->weapon.getType().empty())
		std::cout << this->name << "attacks with their bare hands" << std::endl;
	else
		std::cout << this->name << "attacks with their" << this->weapon.getType() << std::endl;
}

void HumanB::setWeapon(const Weapon &weapon) {
	this->weapon = weapon;
}
