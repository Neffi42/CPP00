#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"
#include <iostream>

int main(){
    Intern someRandomIntern;
    Bureaucrat andy("Andy Malgonn", 1);
    AForm *rff = NULL;

    std::cout << "\n";
    try {
        rff = someRandomIntern.makeForm("Robotomy Request Form", "Andrew Attali");
        andy.signForm(*rff);
        andy.executeForm(*rff);
    }
    catch (std::exception &e) {
        std::cerr << e.what() << "\n";
    }

    if (rff) {
        delete rff;
    }

    std::cout << "\n";
    try {
        rff = someRandomIntern.makeForm("RobotomyRequestForm", "Andrew Attali");
        andy.signForm(*rff);
        andy.executeForm(*rff);
    }
    catch (std::exception &e) {
        std::cerr << e.what() << "\n";
    }

    if (rff) {
        delete rff;
    }
}
