#include "Cat.hpp"

Cat::Cat() {
    std::cout << "Cat's default constructor called" << std::endl;
    type = "Cat";
    brain = new Brain();
}

Cat::Cat(const Cat &other) {
    std::cout << "Cat's copy constructor called" << std::endl;
    *this = other;
}

Cat::~Cat() {
    std::cout << "Cat's copy destructor called" << std::endl;
    delete brain;
}

const Cat &Cat::operator=(const Cat &other) {
    if (this != &other) {
        Animal::operator=(other);
        delete brain;
        brain = new Brain(other.brain->ideas);
    }
    return *this;
}

void Cat::makeSound() const {
    std::cout << "Cat says meow" << std::endl;
}
