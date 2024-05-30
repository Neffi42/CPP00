#pragma once

#include <cstddef>
#include <iostream>


template <typename T>
void iter(T* array, const size_t &len, void (*f)(const T&)) {
	if (array == NULL || f == NULL)
		return ;
    for (size_t i = 0; i < len; i++) {
        f(array[i]);
    }
}

template  <typename T>
void print(const T& el) {
    std::cout << el << "\n";
}
