#pragma once

#include <cstddef>
#include <iostream>

template <typename T>
Array<T>::Array(): content(new T[0]), len(0) {
    std::cout << "Array's default constructor called\n";
}

template <typename T>
Array<T>::Array(unsigned int n): content(new T[n]), len(n) {
    for (size_t i = 0; i < n; i++) {
        content[i] = 0;
    }
    std::cout << "Array's param constructor called\n";

}

template <typename T>
Array<T>::Array(Array& other): content(NULL), len(0) {
    std::cout << "Array's copy constructor called\n";
    *this = other;
}

template <typename T>
Array<T>::~Array() {
    std::cout << "Array's destructor called\n";
    delete [] content;
}

template <typename T>
const Array<T>& Array<T>::operator=(Array& other) {
    std::cout << "Array's copy assignement operator constructor called\n";
    if (this != &other) {
        len = other.len;
        if (content) {
            delete [] content;
        }
        content = new T[len];
        for (size_t i = 0; i < len; i++) {
            content[i] = other.content[i];
        }
    }
    return *this;
}

template <typename T>
T& Array<T>::operator[](size_t i) const {
    if (i < len) {
        return content[i];
    }
    else {
        throw Array<T>::OutOfBoundsException();
    }
}

template <typename T>
size_t Array<T>::size() const {
    return len;
}

template <typename T>
const char* Array<T>::OutOfBoundsException::what() const throw() {
    return "Value is out of bounds";
}

template <typename T>
std::ostream& operator<<(std::ostream& o, const Array<T>& array) {
    for (size_t i = 0; i < array.size(); i++) {
        o << array[i];
        if (i + 1 < array.size()) {
            o << " ";
        }
    }
    return o;
}
