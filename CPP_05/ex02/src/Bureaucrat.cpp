#include "Bureaucrat.hpp"
#include <exception>

Bureaucrat::Bureaucrat(): name("Default"), grade(150) {
    std::cout << "Bureaucrat's default constructor called\n";
}

Bureaucrat::Bureaucrat(const std::string &name, int grade): name(name) {
    std::cout << "Bureaucrat's params constructor called\n";
    try {
        setGrade(grade);
    }
    catch(const std::exception &e) {
        this->grade = 150;
    }
}

Bureaucrat::Bureaucrat(const Bureaucrat &other): name(other.name) {
    std::cout << "Bureaucrat's copy constructor called\n";
    *this = other;
}

Bureaucrat::~Bureaucrat() {
    std::cout << "Bureaucrat's destructor called\n";
}

const Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other) {
    std::cout << "Bureaucrat's copy assignement operator called\n";
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
    catch(const std::exception &e) {
        std::cerr << e.what() << "\n";
    }
}

void Bureaucrat::decrementGrade() {
    try {
        setGrade(grade + 1);
    }
    catch(const std::exception &e) {
        std::cerr << e.what() << "\n";
    }
}

int Bureaucrat::getGrade() const {
    return grade;
}

std::string Bureaucrat::getName() const {
    return name;
}

void Bureaucrat::signForm(AForm &a) {
    try {
        a.beSigned(*this);
        std::cout << name << " signed " << a.getName() << "\n";
    } catch (const std::exception &e) {
        std::cerr << name << " couldn't sign " << a.getName() << " because: " << e.what() << "\n";
    }
}

void Bureaucrat::executeForm(const AForm &form) {
    try {
        form.execute(*this);
        std::cout << name << " executed " << form.getName() << "\n";
    } catch (const std::exception &e) {
        std::cerr << name << " couldn't execute " << form.getName() << " because: " << e.what() << "\n";
    }
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
