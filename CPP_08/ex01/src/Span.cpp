#include "Span.hpp"
#include <algorithm>
#include <cstddef>
#include <cstdlib>
#include <iostream>
#include <ctime>
#include <iterator>
#include <numeric>
#include <vector>

Span::Span(): N(5) {
    vec.reserve(N);
}

Span::Span(unsigned int N): N(N) {
    vec.reserve(N);
}

Span::Span(const Span& other) {
    *this = other;
}

Span::~Span() {}

const Span& Span::operator=(const Span&other) {
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
    std::vector<int> copy(vec);
	std::sort(copy.begin(), copy.end());
	std::adjacent_difference(copy.begin(), copy.end(), copy.begin());
	return *std::min_element(copy.begin(), copy.end());
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
