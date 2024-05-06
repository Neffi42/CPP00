#include "Character.hpp"

Character::Character(std::string name): name(name), size(0) {
    std::cout << "Character " << name << "'s default constructor called" << std::endl;
    for (int i = 0; i < MAX_SIZE; i++) {
        inventory[i] = NULL;
    }
}

Character::Character(Character &other) {
    std::cout << "Character " << name << "'s copy constructor called" << std::endl;
    *this = other;
}

Character::~Character() {
    std::cout << "Character " << name << "'s destructor called" << std::endl;
    for (int i = 0; i < size; i++) {
        delete inventory[i];
    }
}
const Character &Character::operator=(Character &other) {
    std::cout << "Character " << name << "'s copy assignement operator called" << std::endl;
    if (this != &other) {
        name = other.name;
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

const std::string &Character::getName() const {
    return name;
}

void Character::equip(AMateria* m) {
    if (size < MAX_SIZE) {
        for (int i = 0; i < size; i++) {
            if (&m == &inventory[i]) {
                std::cout << "Materia already in " << name << " inventory" << std::endl;
                return;
            }
        }
        inventory[size++] = m;
    }
}

void Character::unequip(int idx) {
    if (size > 0 && idx >= 0 && idx < size) {
        inventory[idx] = NULL;
        size--;
    }
}

void Character::use(int idx, ICharacter &target){
    if (size > 0 && idx >= 0 && idx < size) {
        inventory[idx]->use(target);
    }
}
