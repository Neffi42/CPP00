#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(): type("Default") {
    std::cout << "WrongAnimal's default constructor called" << std::endl;
    type = "";
}

WrongAnimal::WrongAnimal(const std::string &type): type(type) {
    std::cout << "WrongAnimal's type constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &other) {
    std::cout << "WrongAnimal's copy constructor called" << std::endl;
    *this = other;
}

WrongAnimal::~WrongAnimal() {
    std::cout << "WrongAnimal's destructor called" << std::endl;
}

const WrongAnimal &WrongAnimal::operator=(const WrongAnimal &other) {
    std::cout << "WrongAnimal's copy assignement operator called" << std::endl;
    if (this != &other)
        this->type = other.type;
    return *this;
}

const std::string &WrongAnimal::getType() const {
    return type;
}

void WrongAnimal::makeSound() const {}
