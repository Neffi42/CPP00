#include "HumanB.hpp"

HumanB::HumanB(std::string name): _name(name), _weapon("") {}

HumanB::~HumanB() {}

void HumanB::attack() {
	if (this->_weapon.getType().empty())
		std::cout << this->_name << "attacks with their bare hands" << std::endl;
	else
		std::cout << this->_name << "attacks with their" << this->_weapon.getType() << std::endl;
}

void HumanB::setWeapon(Weapon weapon) {
	this->_weapon = weapon;
}
