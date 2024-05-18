#include "Span.hpp"
#include <algorithm>
#include <cstddef>
#include <cstdlib>
#include <iostream>
#include <ctime>
#include <iterator>
#include <vector>

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
        vec = other.vec;
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
    if (vec.size() < 2) {
        throw NotEnoughIntException();
    }

    int shortest = 0;
    int tmp = 0;
    for (std::vector<int>::iterator i = vec.begin(); i != vec.end() - 1; i++) {
        tmp = std::abs(*i - *(i + 1));
        if (tmp < shortest || shortest == 0) {
            shortest = tmp;
        }
    }

    return shortest;
}

int Span::longestSpan() {
    if (vec.size() < 2) {
        throw NotEnoughIntException();
    }
    return *std::max_element(vec.begin(), vec.end()) - *std::min_element(vec.begin(), vec.end());
}

void Span::fillSpan() {
    vec.resize(N);
    std::srand(unsigned(std::time(NULL)));
    std::generate(vec.begin(), vec.end(), std::rand);
}

void Span::print() const {
    std::copy(vec.begin(), vec.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << "\n";
}

const char* Span::SpanFullException::what() const throw() {
    return "Span is already full";
}

const char* Span::NotEnoughIntException::what() const throw() {
    return "There is not enough integers inside the span";
}