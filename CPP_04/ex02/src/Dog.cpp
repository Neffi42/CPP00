#include "Dog.hpp"

Dog::Dog(): Animal("Dog") {
    std::cout << "Dog's default constructor called" << std::endl;
    brain = new Brain();
}

Dog::Dog(const Dog &other): Animal(other) {
    std::cout << "Dog's copy constructor called" << std::endl;
    *this = other;
}

Dog::~Dog() {
    std::cout << "Dog's destructor called" << std::endl;
    delete brain;
}

const Dog &Dog::operator=(const Dog &other) {
    std::cout << "Dog's copy assignement operator called" << std::endl;
    if (this != &other) {
        Animal::operator=(other);
        delete brain;
        brain = new Brain(other.brain->ideas);
    }
    return *this;
}

void Dog::makeSound() const {
    std::cout << "Dog says woof" << std::endl;
}
