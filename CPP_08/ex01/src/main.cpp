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
    {
		try {
			Span sp(0);
			sp.addNumber(1);
		}
		catch (const std::exception& e) {
			std::cerr << e.what() << '\n';
		}
	}
	{
		try {
			Span sp(1);
			sp.addNumber(1);
			std::cout << sp.longestSpan() << std::endl;
		}
		catch (const std::exception& e) {
			std::cerr << e.what() << '\n';
		}
    }
    return 0;
}
