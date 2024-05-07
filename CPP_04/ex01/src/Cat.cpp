#include "Cat.hpp"

Cat::Cat(): Animal("Cat") {
    std::cout << "Cat's default constructor called" << std::endl;
    brain = new Brain();
}

Cat::Cat(const Cat &other): Animal(other) {
    std::cout << "Cat's copy constructor called" << std::endl;
    *this = other;
}

Cat::~Cat() {
    std::cout << "Cat's destructor called" << std::endl;
    delete brain;
}

const Cat &Cat::operator=(const Cat &other) {
    std::cout << "Cat's copy assignement operator called" << std::endl;
    if (this != &other) {
        Animal::operator=(other);
        delete brain;
        brain = new Brain(*other.brain);
    }
    return *this;
}

void Cat::makeSound() const {
    std::cout << "Cat says meow" << std::endl;
}

void Cat::setIdea(std::string idea, int index) {
    if (index >= 0 && index < MAX_IDEA) {
        brain->ideas[index] = idea;
    }
}

std::string Cat::getIdea(int index) {
    if (index >= 0 && index < MAX_IDEA) {
        return brain->ideas[index];
    }
    return "";
}
