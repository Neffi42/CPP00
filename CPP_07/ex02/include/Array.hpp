#pragma once

#include <cstddef>
#include <exception>
#include <ostream>
#include <iostream>

template <typename T>
class Array {
private:
    T *content;
    size_t len;
public:
    Array();
    Array(unsigned int n);
    Array(Array& other);
    ~Array();

    const Array& operator=(Array& other);
    T& operator[](size_t i) const;

    size_t size() const;

    class OutOfBoundsException: public std::exception {
    public:
        virtual const char* what() const throw();
    };
};

template <typename T>
std::ostream& operator<<(std::ostream& o, const Array<T>& array);

#include "Array.tpp"
