#include "ShrubberyCreationForm.hpp"
#include "AForm.hpp"
#include <cstdio>
#include <fstream>
#include <iostream>

ShrubberyCreationForm::ShrubberyCreationForm(): AForm("Shrubbery", 145, 137), target("Default") {
    std::cout << "ShrubberyCreationForm's default constructor called\n";
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target): AForm("Shrubbery", 145, 137), target(target) {
    std::cout << "ShrubberyCreationForm's params constructor called\n";
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other): AForm(other) {
    std::cout << "ShrubberyCreationForm's copy constructor called\n";
    *this = other;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
    std::cout << "ShrubberyCreationForm's destructor called\n";
}

const ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other) {
    std::cout << "ShrubberyCreationForm's copy assignement operator called\n";
    if (this != &other) {
        AForm::operator=(other);
        target = other.target;
    }
    return *this;
}

void ShrubberyCreationForm::beExecuted() const {
    std::fstream file((target + "_shrubbery").c_str(), std::fstream::out);
    if (file.bad()) {
        std::cerr << "Cannot open " << target << "_shrubbery file\n";
    }
    else {
        file << tree;
    }
}
