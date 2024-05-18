#include "Span.hpp"
#include <iostream>

int main() {
    {
        Span sp = Span(5);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);
        std::cout << sp.shortestSpan() << "\n";
        std::cout << sp.longestSpan() << "\n";
    }
    std::cout << "\n";
    {
        Span sp = Span(100);
        sp.fillSpan();
        // sp.print();
        std::cout << sp.shortestSpan() << "\n";
        std::cout << sp.longestSpan() << "\n";
    }
    std::cout << "\n";
    {
        Span sp = Span(10000);
        sp.fillSpan();
        std::cout << sp.shortestSpan() << "\n";
        std::cout << sp.longestSpan() << "\n";
    }
    return 0;
}
