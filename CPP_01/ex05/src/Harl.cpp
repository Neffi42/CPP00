#include "Harl.hpp"

Harl::Harl() {
	this->levels["DEBUG"] = &Harl::debug;
	this->levels["INFO"] = &Harl::info;
	this->levels["WARNING"] = &Harl::warning;
	this->levels["ERROR"] = &Harl::error;
}

Harl::~Harl() {}

void Harl::complain(const std::string &level) {
	if (this->levels.find(level) != this->levels.end())
		(this->*levels[level])();
}

void Harl::debug() {
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << std::endl;
}

void Harl::info() {
	std::cout << "I cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!" << std::endl;
}

void Harl::warning() {
	std::cout << "I think I deserve to have some extra bacon for free. I've been coming foryears whereas you started working here since last month." << std::endl;
}

void Harl::error() {
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}
