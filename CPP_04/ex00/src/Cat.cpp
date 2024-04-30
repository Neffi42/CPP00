#include "Cat.hpp"

Cat::Cat() {
    std::cout << "Cat's default constructor called" << std::endl;
    type = "Cat";
}

Cat::Cat(const Cat &other) {
    std::cout << "Cat's copy constructor called" << std::endl;
    *this = other;
}

Cat::~Cat() {
    std::cout << "Cat's copy destructor called" << std::endl;
}

const Cat &Cat::operator=(const Cat &other) {
    (void)other;
    return *this;
}

void Cat::makeSound() const {
    std::cout << "Cat says meow" << std::endl;
}
