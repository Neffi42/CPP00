#pragma once

#include <exception>
#include <vector>

class Span {
private:
    unsigned int N;
    std::vector<int> vec;
public:
    Span();
    Span(unsigned int N);
    Span(const Span& other);
    ~Span();

    const Span& operator=(const Span&other);

    void addNumber(int n);
    int shortestSpan();
    int longestSpan();
    void fillSpan();
    void print();

    class SpanFullException: public std::exception {
        virtual const char* what() const throw();
    };
    class NotEnoughIntException: public std::exception {
        virtual const char* what() const throw();
    };
};
