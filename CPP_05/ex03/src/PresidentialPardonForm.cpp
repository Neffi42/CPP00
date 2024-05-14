#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(): AForm("Presidential", 25, 5), target("Default") {
    std::cout << "PresidentialPardonForm's default constructor called\n";
}

PresidentialPardonForm::PresidentialPardonForm(std::string target): AForm("Presidential", 25, 5), target(target) {
    std::cout << "PresidentialPardonForm's params constructor called\n";
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other): AForm(other) {
    std::cout << "PresidentialPardonForm's copy constructor called\n";
    *this = other;
}

PresidentialPardonForm::~PresidentialPardonForm() {
    std::cout << "PresidentialPardonForm's destructor called\n";
}

const PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &other) {
    std::cout << "PresidentialPardonForm's copy assignement operator called\n";
    if (this != &other) {
        AForm::operator=(other);
        target = other.target;
    }
    return *this;
}

void PresidentialPardonForm::beExecuted() const {
    std::cout << target << " has been pardoned by Zaphod Beeblebrox\n";
}
