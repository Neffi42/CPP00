#include "Zombie.hpp"

Zombie::Zombie(): name("") {};

Zombie::Zombie(const std::string &name): name(name) {}

Zombie::~Zombie() {
	std::cout << this->name << ": calling destructor" << std::endl;
}

void	Zombie::setName(const std::string &name) {
	this->name = name;
}

void	Zombie::announce() {
	std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
