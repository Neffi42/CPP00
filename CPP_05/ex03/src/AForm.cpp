#include "AForm.hpp"

AForm::AForm(): name("Default"), sign(false), gradeToSign(150), gradeToExecute(150) {
    std::cout << "AForm's default constructor called" << std::endl;
}

AForm::AForm(std::string name, int gradeToSign, int gradeToExecute): name(name), sign(false), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute) {
    std::cout << "AForm's params constructor called" << std::endl;
    if (gradeToSign < 1 || gradeToExecute < 1) {
        throw AForm::GradeTooHighException();
    }
    else if (gradeToSign > 150 || gradeToExecute > 150) {
        throw AForm::GradeTooLowException();
    }
}

AForm::AForm(const AForm &other): name(other.name), sign(false), gradeToSign(other.gradeToSign), gradeToExecute(other.gradeToExecute) {
    std::cout << "AForm's copy constructor called" << std::endl;
    *this = other;
}

AForm::~AForm() {
    std::cout << "AForm's destructor called" << std::endl;
}

const AForm &AForm::operator=(const AForm &other) {
    std::cout << "AForm's copy assignement operator called" << std::endl;
    if (this != &other) {
        sign = other.sign;
    }
    return *this;
}

std::string AForm::getName() const {
    return name;
}

bool AForm::getSign() const {
    return sign;
}

int AForm::getGradeToSign() const {
    return gradeToSign;
}

int AForm::getGradeToExecute() const {
    return gradeToExecute;
}

void AForm::beSigned(const Bureaucrat &a) {
    if (a.getGrade() > gradeToSign) {
        throw AForm::GradeTooLowException();
    }
    else if (sign == true) {
        throw AForm::AlreadySigned();
    }
    else {
        sign = true;
    }
}

void AForm::execute(const Bureaucrat &executor) const {
    if (sign == false) {
        throw  AForm::NotSigned();
    }
    else if (executor.getGrade() > gradeToExecute) {
        throw AForm::GradeTooLowException();
    }
    else {
        beExecuted();
    }
}

const char *AForm::GradeTooLowException::what() const throw() {
    return "Grade is too low";
}

const char *AForm::GradeTooHighException::what() const throw() {
    return "Grade is too high";
}

const char *AForm::AlreadySigned::what() const throw() {
    return "AForm is already signed";
}

const char *AForm::NotSigned::what() const throw() {
    return "AForm is not signed";
}

std::ostream &operator<<(std::ostream &o, const AForm &a) {
    o << a.getName() <<", form signed bool " << a.getSign() << ", form gradeToSign " << a.getGradeToSign() << ", form gradeToExecute " << a.getGradeToExecute() << ".";
    return o;
}
