#include "Ice.hpp"

Ice::Ice(): AMateria("ice") {
    std::cout << "Ice's default constructor called" << std::endl;
}

Ice::Ice(const Ice &other): AMateria(other) {
    std::cout << "Ice's copy constructor called" << std::endl;
    *this = other;
}

Ice::~Ice() {
    std::cout << "Ice's destructor called" << std::endl;
}

const Ice &Ice::operator=(const Ice &other) {
    std::cout << "Ice's copy assignement operator called" << std::endl;
    (void)other;
    return *this;
}

Ice *Ice::clone() const {
    Ice *dup = new Ice(*this);
    return dup;
}

void Ice::use(ICharacter &target) {
    std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
