#include "Animal.hpp"

Animal::Animal() {
    std::cout << "Animal's default constructor called" << std::endl;
    type = "";
}

Animal::Animal(const Animal &other) {
    std::cout << "Animal's copy constructor called" << std::endl;
    *this = other;
}

Animal::~Animal() {
    std::cout << "Animal's destructor called" << std::endl;
}

const Animal &Animal::operator=(const Animal &other) {
    if (this != &other)
        this->type = other.type;
    return *this;
}

const std::string &Animal::getType() const {
    return type;
}

void Animal::makeSound() const {}
