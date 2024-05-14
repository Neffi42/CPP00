#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
    {
        Form f1("F1", 42, 46);
        std::cout << f1 << std::endl;

        Form f2(f1);
        std::cout << f2 << std::endl;

        try {
            Form f3("F3", 666, 42);
        } catch (const std::exception &e) {
            std::cerr << e.what() << std::endl;
        }
    }
    std::cout << std::endl;
    {
        Bureaucrat john("John", 42);

        Form f1("F1", 42, 46);
        std::cout << f1 << std::endl;
        f1.beSigned(john);
        std::cout << f1 << std::endl;
        try {
            f1.beSigned(john);
        } catch (const std::exception &e) {
            std::cerr << e.what() << std::endl;
        }

        Form f2("F2", 42, 46);
        std::cout << f2 << std::endl;
        john.signForm(f2);
        std::cout << f2 << std::endl;
        try {
            john.signForm(f2);
        } catch (const std::exception &e) {
            std::cerr << e.what() << std::endl;
        }

        Form f3("F3", 1, 46);
        std::cout << f3 << std::endl;
        try {
            john.signForm(f3);
        } catch (const std::exception &e) {
            std::cerr << e.what() << std::endl;
        }
    }
    return 0;
}
