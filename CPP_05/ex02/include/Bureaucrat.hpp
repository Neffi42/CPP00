#pragma once

#include <iostream>
#include <string>
#include <exception>
#include <ostream>
#include "AForm.hpp"

class AForm;

class Bureaucrat {
private:
    const std::string name;
    int grade;
    void setGrade(int newGrade);
public:
    Bureaucrat();
    Bureaucrat(const std::string &name, int grade);
    Bureaucrat(const Bureaucrat &other);
    ~Bureaucrat();
    const Bureaucrat &operator=(const Bureaucrat &other);

    void incrementGrade();
    void decrementGrade();
    int getGrade() const;
    std::string getName() const;
    void signForm(AForm &a);

    class GradeTooLowException: public std::exception {
    public:
        virtual const char *what() const throw();
	};
	class GradeTooHighException: public std::exception {
    public:
        virtual const char *what() const throw();
	};
};

std::ostream &operator<<(std::ostream &o, const Bureaucrat &a);
