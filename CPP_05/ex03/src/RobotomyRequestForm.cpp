#include "RobotomyRequestForm.hpp"
#include "AForm.hpp"
#include <cstdlib>

RobotomyRequestForm::RobotomyRequestForm(): AForm("Robotomy", 72, 45), target("Default") {
    std::cout << "RobotomyRequestForm's default constructor called\n";
}

RobotomyRequestForm::RobotomyRequestForm(std::string target): AForm("Robotomy", 72, 45), target(target) {
    std::cout << "RobotomyRequestForm's params constructor called\n";
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other): AForm(other) {
    std::cout << "RobotomyRequestForm's copy constructor called\n";
    *this = other;
}

RobotomyRequestForm::~RobotomyRequestForm() {
    std::cout << "RobotomyRequestForm's destructor called\n";
}

const RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other) {
    std::cout << "RobotomyRequestForm's copy assignement operator called\n";
    if (this != &other) {
        AForm::operator=(other);
        target = other.target;
    }
    return *this;
}

void RobotomyRequestForm::beExecuted() const {
    srand((unsigned) time(NULL));
    if (!(rand() % 2)) {
        std::cout << target << " has been robotomized\n";
    }
    else {
        std::cout << "Robotomy has failed\n";
    }
}
