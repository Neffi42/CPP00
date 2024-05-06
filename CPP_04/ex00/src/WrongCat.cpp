#include "WrongCat.hpp"

WrongCat::WrongCat(): WrongAnimal("WrongCat") {
    std::cout << "WrongCat's default constructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat &other) {
    std::cout << "WrongCat's copy constructor called" << std::endl;
    *this = other;
}

WrongCat::~WrongCat() {
    std::cout << "WrongCat's copy destructor called" << std::endl;
}

const WrongCat &WrongCat::operator=(const WrongCat &other) {
    (void)other;
    return *this;
}

void WrongCat::makeSound() const {
    std::cout << "WrongCat says meow" << std::endl;
}
