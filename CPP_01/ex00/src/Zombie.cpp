#include "Zombie.hpp"

Zombie::Zombie(const std::string &name): name(name) {}

Zombie::~Zombie() {
	std::cout << this->name << ": calling destructor" << std::endl;
}

void	Zombie::announce() {
	std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
