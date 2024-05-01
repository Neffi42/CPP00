#include "Brain.hpp"

Brain::Brain() {
    std::cout << "Brain's default constructor called" << std::endl;
}

Brain::Brain(const Brain &other) {
    std::cout << "Brain's copy constructor called" << std::endl;
    *this = other;
}

Brain::~Brain() {
    std::cout << "Brain's destructor called" << std::endl;
}

const Brain &Brain::operator=(const Brain &other) {
    if (this != &other) {
        for (size_t i = 0; i < 100; i++) {
            this->ideas[i] = other.ideas[i];
        }
    }
    return *this;
}
