#include "AMateria.hpp"

AMateria::AMateria(const std::string &type): type(type) {
    std::cout << "AMateria's default constuctor called" << std::endl;
}

AMateria::AMateria(const AMateria &other) {
    std::cout << "AMateria's copy constuctor called" << std::endl;
    *this = other;
}

AMateria::~AMateria() {
    std::cout << "AMateria's destructor called" << std::endl;
}

const AMateria &AMateria::operator=(const AMateria &other) {
    std::cout << "AMateria's copy assignement operator called" << std::endl;
    if (this != &other) {
        type = other.type;
    }
    return *this;
}

const std::string &AMateria::getType() const {
    return type;
}

void AMateria::use(ICharacter &target) {
    std::cout << "Use method called on " << target.getName() << std::endl;
}
