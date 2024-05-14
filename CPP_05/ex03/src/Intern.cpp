#include "Intern.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

Intern::Intern() {
    std::cout << "Intern's default constructor called\n";
}

Intern::Intern(const Intern &other) {
    std::cout << "Intern's copy constructor called\n";
    (void)other;
}

Intern::~Intern() {
    std::cout << "Intern's destructor called\n";
}

const Intern &Intern::operator=(const Intern &other) {
    std::cout << "Intern's copy assignement operator called\n";
    (void)other;
    return *this;
}

AForm *Intern::makePresidential(std::string target) const {
    AForm *form = new PresidentialPardonForm(target);
    return form;
}

AForm *Intern::makeRobotomy(std::string target) const {
    AForm *form = new RobotomyRequestForm(target);
    return form;
}

AForm *Intern::makeShrubbery(std::string target) const {
    AForm *form = new ShrubberyCreationForm(target);
    return form;
}

AForm *Intern::makeForm(std::string name, std::string target) const {
    AForm *(Intern::*f[3])(std::string) const = {&Intern::makePresidential, &Intern::makeRobotomy, &Intern::makeShrubbery};
    std::string forms[3] = {"PresidentialPardonForm", "RobotomyRequestForm", "ShrubberyCreationForm"};
    AForm *newForm = NULL;

    for (int i = 0; i < 3; i++) {
        if (forms[i] == name) {
            newForm = (this->*f[i])(target);
            std::cout << "Intern creates " << name << "\n";
        }
    }

    if (newForm == NULL) {
        throw Intern::NoForm();
    }

    return newForm;
}

const char *Intern::NoForm::what() const throw() {
    return "Form doesn't exist";
}
