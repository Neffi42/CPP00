#include "Form.hpp"

Form::Form(): name("Default"), sign(false), gradeToSign(150), gradeToExecute(150) {
    std::cout << "Form's default constructor called" << std::endl;
}

Form::Form(std::string name, int gradeToSign, int gradeToExecute): name(name), sign(false), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute) {
    std::cout << "Form's params constructor called" << std::endl;
    if (gradeToSign < 1 || gradeToExecute < 1) {
        throw Form::GradeTooHighException();
    }
    else if (gradeToSign > 150 || gradeToExecute > 150) {
        throw Form::GradeTooLowException();
    }
}

Form::Form(const Form &other): name(other.name), sign(false), gradeToSign(other.gradeToSign), gradeToExecute(other.gradeToExecute) {
    std::cout << "Form's copy constructor called" << std::endl;
    *this = other;
}

Form::~Form() {
    std::cout << "Form's destructor called" << std::endl;
}

const Form &Form::operator=(const Form &other) {
    std::cout << "Form's copy assignement operator called" << std::endl;
    if (this != &other) {
        sign = other.sign;
    }
    return *this;
}

std::string Form::getName() const {
    return name;
}

bool Form::getSign() const {
    return sign;
}

int Form::getGradeToSign() const {
    return gradeToSign;
}

int Form::getGradeToExecute() const {
    return gradeToExecute;
}

void Form::beSigned(const Bureaucrat &a) {
    if (a.getGrade() > gradeToSign) {
        throw Form::GradeTooLowException();
    }
    else if (sign == true) {
        throw Form::AlreadySigned();
    }
    else {
        sign = true;
    }
}

const char *Form::GradeTooLowException::what() const throw() {
    return "Grade is too low";
}

const char *Form::GradeTooHighException::what() const throw() {
    return "Grade is too high";
}

const char *Form::AlreadySigned::what() const throw() {
    return "Form is already signed";
}

std::ostream &operator<<(std::ostream &o, const Form &a) {
    o << a.getName() <<", form signed bool " << a.getSign() << ", form gradeToSign " << a.getGradeToSign() << ", form gradeToExecute " << a.getGradeToExecute() << ".";
    return o;
}
