#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstddef>
#include <cstdlib>
#include <ctime>
#include <iostream>

typedef enum {
    type_A = 0,
    type_B,
    type_C
} types;

Base* generate(void) {
    Base* p = NULL;

    srand((unsigned) time(NULL));
    int n = rand() % 3;

    switch (n) {
        case type_A:
            p = new A;
            break;
        case type_B:
            p = new B;
            break;
        case type_C:
            p = new C;
            break;
    }

    return p;
}

void identify(Base* p) {
    if (dynamic_cast<A*>(p))
        std::cout << "A\n";
    else if (dynamic_cast<B*>(p))
        std::cout << "B\n";
    else if (dynamic_cast<C*>(p))
        std::cout << "C\n";
}

void identify(Base& p) {
    try {
        A& a = dynamic_cast<A&>(p);
        (void)a;
        std::cout << "A" << std::endl;
    }
    catch(const std::exception& e) {}
    try {
        B& b = dynamic_cast<B&>(p);
        (void)b;
        std::cout << "B" << std::endl;
    }
    catch(const std::exception& e) {}
    try {
        C& c = dynamic_cast<C&>(p);
        (void)c;
        std::cout << "C" << std::endl;
    }
    catch(const std::exception& e) {}
}

int main() {
    Base* p = generate();

    identify(p);
    identify(*p);

    delete p;
}
