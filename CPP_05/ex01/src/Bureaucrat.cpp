#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(): name("Default"), grade(150) {
    std::cout << "Bureaucrat's default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string &name, int grade): name(name) {
    std::cout << "Bureaucrat's name and grade constructor called" << std::endl;
    try {
        setGrade(grade);
    }
    catch(const std::exception& e) {
        this->grade = 150;
    }
}

Bureaucrat::Bureaucrat(const Bureaucrat &other): name(other.name) {
    std::cout << "Bureaucrat's copy constructor called" << std::endl;
    *this = other;
}

Bureaucrat::~Bureaucrat() {
    std::cout << "Bureaucrat's destructor called" << std::endl;
}

const Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other) {
    std::cout << "Bureaucrat's copy assignement operator called" << std::endl;
    if (this != &other) {
        setGrade(other.grade);
    }
    return *this;
}

void Bureaucrat::setGrade(int newGrade) {
    if (newGrade < 1) {
        throw Bureaucrat::GradeTooHighException();
    }
    else if (newGrade > 150) {
        throw Bureaucrat::GradeTooLowException();
    }
    else {
        grade = newGrade;
    }
}

void Bureaucrat::incrementGrade() {
    try {
        setGrade(grade - 1);
    }
    catch(const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
}

void Bureaucrat::decrementGrade() {
    try {
        setGrade(grade + 1);
    }
    catch(const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
}

int Bureaucrat::getGrade() const {
    return grade;
}

std::string Bureaucrat::getName() const {
    return name;
}

const char *Bureaucrat::GradeTooLowException::what() const throw() {
    return "Grade is too low";
}

const char *Bureaucrat::GradeTooHighException::what() const throw() {
    return "Grade is too high";
}

std::ostream &operator<<(std::ostream &o, const Bureaucrat &a) {
    o << a.getName() <<", bureaucrat grade " << a.getGrade() << ".";
    return o;
}
