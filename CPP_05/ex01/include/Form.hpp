#pragma once

#include <iostream>
#include <string>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form {
private:
    const std::string name;
    bool sign;
    const int gradeToSign;
    const int gradeToExecute;
public:
    Form();
    Form(std::string name, int gradeToSign, int gradeToExecute);
    Form(const Form &other);
    ~Form();

    const Form &operator=(const Form &other);

    std::string getName() const;
    bool getSign() const;
    int getGradeToSign() const;
    int getGradeToExecute() const;
    void beSigned(const Bureaucrat &a);

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

std::ostream &operator<<(std::ostream &o, const Form &a);
