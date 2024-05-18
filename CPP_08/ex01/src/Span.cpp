#include "Span.hpp"
#include <algorithm>
#include <cstddef>
#include <cstdlib>
#include <iostream>
#include <ctime>
#include <iterator>

Span::Span(): N(5) {
    std::cout << "Span's default constructor called\n";
    vec.reserve(N);
}

Span::Span(unsigned int N): N(N) {
    std::cout << "Span's param constructor called\n";
    vec.reserve(N);
}

Span::Span(const Span& other) {
    std::cout << "Span's copy constructor called\n";
    *this = other;
}

Span::~Span() {
    std::cout << "Span's destructor called\n";
}

const Span& Span::operator=(const Span&other) {
    std::cout << "Span's copy assignement operator called\n";
    if (this != &other) {
        N = other.N;
        vec.clear();
        vec.reserve(N);
        std::copy(other.vec.begin(), other.vec.end(), vec.begin());
    }
    return *this;
}

void Span::addNumber(int n) {
    if (vec.size() == N) {
        throw SpanFullException();
    }
    vec.push_back(n);
}

int Span::shortestSpan() {
    return 0;
}

int Span::longestSpan() {
    return 0;
}

void Span::fillSpan() {
    std::srand(unsigned(std::time(nullptr)));
    std::generate(vec.begin(), vec.end(), std::rand);
}

void Span::print() {
    std::copy(vec.begin(), vec.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << "\n";
}

const char* Span::SpanFullException::what() const throw() {
    return "Span is already full";
}

const char* Span::NotEnoughIntException::what() const throw() {
    return "There is not enough integers inside the span";
}
