#include "Brain.hpp"

Brain::Brain() {
    std::cout << "Brain's default constructor called" << std::endl;
}

Brain::Brain(const Brain &other) {
    std::cout << "Brain's copy constructor called" << std::endl;
    *this = other;
}

Brain::Brain(const std::string ideas[100]) {
    std::cout << "Brain's ideas constructor called" << std::endl;
    if (!ideas)
        std::memcpy(this->ideas, ideas, 100);
}


Brain::~Brain() {
    std::cout << "Brain's destructor called" << std::endl;
}

const Brain &Brain::operator=(const Brain &other) {
    if (this != &other)
        std::memcpy(ideas, other.ideas, 100);
    return *this;
}
