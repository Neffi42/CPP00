#include "Brain.hpp"

Brain::Brain() {
    std::cout << "Brain's default constructor called" << std::endl;
    for (int i = 0; i < MAX_IDEA; i++) {
        ideas[i] = "";
    }
}

Brain::Brain(const Brain &other) {
    std::cout << "Brain's copy constructor called" << std::endl;
    *this = other;
}

Brain::~Brain() {
    std::cout << "Brain's destructor called" << std::endl;
}

const Brain &Brain::operator=(const Brain &other) {
    std::cout << "Brain's copy assignement operator called" << std::endl;
    if (this != &other) {
        for (size_t i = 0; i < MAX_IDEA; i++) {
            this->ideas[i] = other.ideas[i];
        }
    }
    return *this;
}
