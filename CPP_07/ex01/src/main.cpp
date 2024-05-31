#include "iter.hpp"
#include <iostream>

#define N 5

template  <typename T>
void print(T& el) {
    std::cout << el << "\n";
}

int main() {
    int arr1[] = {1, 2, 3, 4, 5};

    std::cout << "arr1: " << "\n";
    iter(arr1, N, &print<int>);

    double arr2[] = {1.1, 2.2, 3.3, 4.4, 5.5};

    std::cout << "\narr2: " << "\n";
    iter(arr2, N, &print<const double>);

    char arr3[] = { 'a', 'b', 'c', 'd', 'e' };

    std::cout << "\narr3: " << "\n";
    iter(arr3, N, &print<char>);

    std::string arr4[] = {"one", "two", "three", "four", "five"};

    std::cout << "\narr4: " << "\n";
    iter(arr4, N, &print<const std::string>);

    return 0;
}
