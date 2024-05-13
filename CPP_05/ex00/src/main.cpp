#include "Bureaucrat.hpp"

int main() {
    {
        Bureaucrat john("John", 27);
        std::cout << john << std::endl;
        john.decrementGrade();
        std::cout << john << std::endl;
        john.incrementGrade();
        std::cout << john << std::endl;

        Bureaucrat anny("Anny", 1);
        std::cout << anny << std::endl;
        anny = john;
        std::cout << anny << std::endl;

        Bureaucrat def(anny);
        std::cout << def << std::endl;
    }
    std::cout << std::endl;
    {
        Bureaucrat john("John", 150);
        std::cout << john << std::endl;
        john.decrementGrade();
        std::cout << john << std::endl;

        Bureaucrat anny("Anny", 1);
        std::cout << anny << std::endl;
        anny.incrementGrade();
        std::cout << anny << std::endl;
    }
    std::cout << std::endl;
    {
        Bureaucrat john("John", 151);
        std::cout << john << std::endl;
    }
    return 0;
}
