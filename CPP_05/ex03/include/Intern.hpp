#pragma once

#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <exception>
#include <string>


class Intern {
private:
    AForm *makePresidential(std::string target) const;
    AForm *makeRobotomy(std::string target) const;
    AForm *makeShrubbery(std::string target) const;
public:
    Intern();
    Intern(const Intern &other);
    ~Intern();

    const Intern &operator=(const Intern &other);

    AForm *makeForm(std::string name, std::string target) const;

    class NoForm: public std::exception {
    public:
        virtual const char *what() const throw();
    };
};
