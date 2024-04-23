#include "Fixed.hpp"

Fixed::Fixed() {
	std::cout << "Default constructor called" << std::endl;
	this->value = 0;
}

Fixed::Fixed(const int value) {
	std::cout << "Int constructor called" << std::endl;
	this->value = value << this->bits;
}

Fixed::Fixed(const float value) {
	std::cout << "Float constructor called" << std::endl;
	this->value = roundf(value * (1 << this->bits));
}

Fixed::Fixed(const Fixed &other) {
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

Fixed &Fixed::operator=(const Fixed &other) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
		this->value = other.getRawBits();
	return *this;
}

int Fixed::getRawBits() const {
	return this->value;
}

void Fixed::setRawBits(const int raw) {
	this->value = raw;
}

int Fixed::toInt() const {
	return (int) this->value >> this->bits;
}

float Fixed::toFloat() const {
	return (float) this->value / (1 << this->bits);
}

std::ostream &operator<<(std::ostream &os, const Fixed &other) {
	os << other.toFloat();
	return os;
}
