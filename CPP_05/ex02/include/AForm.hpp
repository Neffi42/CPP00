#pragma once

#include <iostream>
#include <string>
#include <exception>
#include <ostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {
private:
    const std::string name;
    bool sign;
    const int gradeToSign;
    const int gradeToExecute;
public:
    AForm();
    AForm(std::string name, int gradeToSign, int gradeToExecute);
    AForm(const AForm &other);
    ~AForm();

    const AForm &operator=(const AForm &other);

    std::string getName() const;
    bool getSign() const;
    int getGradeToSign() const;
    int getGradeToExecute() const;
    void beSigned(const Bureaucrat &a);
    virtual void beExecuted() const = 0;

    class GradeTooLowException: public std::exception {
    public:
        virtual const char *what() const throw();
	};
	class GradeTooHighException: public std::exception {
    public:
        virtual const char *what() const throw();
	};
	class AlreadySigned: public std::exception {
    public:
        virtual const char *what() const throw();
	};
};

std::ostream &operator<<(std::ostream &o, const AForm &a);
