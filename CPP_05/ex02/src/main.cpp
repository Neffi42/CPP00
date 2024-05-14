#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <iostream>

int    main() {
    Bureaucrat    lowlyBureaucrat("Lowly Larry", 142);
    Bureaucrat    averageBureaucrat("Average Andy", 65);
    Bureaucrat    highBureaucrat("High Harry", 6);

    std::cout << std::endl << "Three bureaucrats created:\n"
            "\t" << lowlyBureaucrat << "\n"
            "\t" << averageBureaucrat << "\n"
            "\t" << highBureaucrat << std::endl << std::endl;

    ShrubberyCreationForm    shrubForm("Forest");
    RobotomyRequestForm        robotomyForm("CEO");
    PresidentialPardonForm    pardonForm(highBureaucrat.getName());

    std::cout << std::endl << "Three forms created:\n"
            "\t" << shrubForm << "\n"
            "\t" << robotomyForm << "\n"
            "\t" << pardonForm << std::endl;

    std::cout << std::endl << "-- Signing and executing Shrubbery form:" << std::endl;
    lowlyBureaucrat.signForm(shrubForm);
    lowlyBureaucrat.executeForm(shrubForm);
    averageBureaucrat.executeForm(shrubForm);

    std::cout << std::endl << "-- Signing and executing Presidential Pardon form:" << std::endl;
    highBureaucrat.executeForm(pardonForm);
    highBureaucrat.signForm(pardonForm);
    highBureaucrat.executeForm(pardonForm);
    highBureaucrat.incrementGrade();
    highBureaucrat.executeForm(pardonForm);

    std::cout << std::endl << "-- Signing and executing Robotomy form:" << std::endl;
    averageBureaucrat.executeForm(robotomyForm);
    averageBureaucrat.signForm(robotomyForm);
    averageBureaucrat.executeForm(robotomyForm);
    highBureaucrat.executeForm(robotomyForm);

    std::cout << std::endl;
}
