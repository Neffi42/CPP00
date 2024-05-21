#include "RPN.hpp"
#include <exception>
#include <iostream>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: ./RPN <reverse polish mathematical expression>\n";
        return 2;
    }
    try {
        RPN rpn(argv[1]);
        rpn.execute();
    }
    catch (const std::exception& e) {
        std::cerr << e.what() << "\n";
        return 1;
    }
    return 0;
}
