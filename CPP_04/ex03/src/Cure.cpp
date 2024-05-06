#include "Cure.hpp"

Cure::Cure(): AMateria("cure") {
    std::cout << "Cure's default constructor called" << std::endl;
}

Cure::Cure(const Cure &other): AMateria(other) {
    std::cout << "Cure's copy constructor called" << std::endl;
    *this = other;
}

Cure::~Cure() {
    std::cout << "Cure's destructor called" << std::endl;
}

const Cure &Cure::operator=(const Cure &other) {
    std::cout << "Cure's copy assignement operator called" << std::endl;
    (void)other;
    return *this;
}

Cure *Cure::clone() const {
    Cure *dup = new Cure(*this);
    return dup;
}

void Cure::use(ICharacter &target) {
    std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
