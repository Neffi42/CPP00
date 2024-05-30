#pragma once

#include <algorithm>
#include <exception>
#include <iostream>

class NoOccurenceException: public std::exception {
public:
    virtual const char* what() const throw();
};

const char* NoOccurenceException::what() const throw() {
    return "No occurence was found";
}

template <typename T>
void easyfind(const T& container, int n) {
    if (std::find(container.begin(), container.end(), n) == container.end()) {
        throw NoOccurenceException();
    }
    else {
        std::cout << "Found value\n";
    }
}
