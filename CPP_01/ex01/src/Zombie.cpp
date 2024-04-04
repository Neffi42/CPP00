#include "Zombie.hpp"

Zombie::Zombie(): _name("") {};

Zombie::Zombie(std::string name): _name(name) {}

Zombie::~Zombie()
{
	std::cout << this->_name << ": calling destructor" << std::endl;
}

void	Zombie::set_name(std::string name)
{
	this->_name = name;
}

void	Zombie::announce() {
	std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
