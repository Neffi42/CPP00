#include "Dog.hpp"

Dog::Dog() {
    std::cout << "Dog's default constructor called" << std::endl;
    type = "Dog";
    brain = new Brain();
}

Dog::Dog(const Dog &other) {
    std::cout << "Dog's copy constructor called" << std::endl;
    *this = other;
    delete brain;
}

Dog::~Dog() {
    std::cout << "Dog's copy destructor called" << std::endl;
}

const Dog &Dog::operator=(const Dog &other) {
    (void)other;
    return *this;
}

void Dog::makeSound() const {
    std::cout << "Dog says woof" << std::endl;
}
