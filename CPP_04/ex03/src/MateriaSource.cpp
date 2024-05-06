#include "MateriaSource.hpp"

MateriaSource::MateriaSource() {
    std::cout << "MateriaSource's default constructor called" << std::endl;
    for (int i = 0; i < MAX_SIZE; i++) {
        inventory[i] = NULL;
    }
    size = 0;
}

MateriaSource::MateriaSource(const MateriaSource &other) {
    std::cout << "MateriaSource's copy constructor called" << std::endl;
    *this = other;
}

MateriaSource::~MateriaSource() {
    std::cout << "MateriaSource's destructor called" << std::endl;
    for (int i = 0; i < size; i++) {
        delete inventory[i];
    }
}

const MateriaSource &MateriaSource::operator=(const MateriaSource &other) {
    std::cout << "MateriaSource's copy assignement operator called" << std::endl;
    if (this != &other) {
        for (int i = 0; i < size; i++) {
            delete inventory[i];
        }
        size = other.size;
        for (int i = 0; i < size; i++) {
            inventory[i] = other.inventory[i]->clone();
        }
    }
    return *this;
}

void MateriaSource::learnMateria(AMateria *m) {
    if (size < MAX_SIZE) {
        inventory[size++] = m->clone();
    }
}

AMateria* MateriaSource::createMateria(std::string const &type) {
    if (size > 0) {
        for (int i = size - 1; i >= 0; i--) {
            if (inventory[i]->getType() == type) {
                return inventory[i]->clone();
            }
        }
    }
    return 0;
}
