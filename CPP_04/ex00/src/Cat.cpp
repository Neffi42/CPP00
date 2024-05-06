#include "Cat.hpp"

Cat::Cat(): Animal("Cat") {
    std::cout << "Cat's default constructor called" << std::endl;
}

Cat::Cat(const Cat &other): Animal(other) {
    std::cout << "Cat's copy constructor called" << std::endl;
    *this = other;
}

Cat::~Cat() {
    std::cout << "Cat's destructor called" << std::endl;
}

const Cat &Cat::operator=(const Cat &other) {
    std::cout << "Cat's copy assignement operator called" << std::endl;
    if (this != &other) {
        Animal::operator=(other);
    }
    return *this;
}

void Cat::makeSound() const {
    std::cout << "Cat says meow" << std::endl;
}
