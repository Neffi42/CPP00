#include <cstdlib>
#include <exception>
#include <iostream>
#include <Array.hpp>

#define SIZE 10

int main() {
    Array<float> test;
    try {
        std::cout << "Accessing an invalid index: " << test[0] << "\n";
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << "\n";
    }

    Array<int> intArray(SIZE);
    Array<int> intArray2(SIZE - 5);

    std::cout << "Int Array 1: " << intArray << "\n";

    for (unsigned int i = 0; i < intArray.size(); i++)
        intArray[i] = i * 2;

    std::cout << "Int Array 1: " << intArray << "\n";

    intArray2 = intArray;

    std::cout << "int Array 2: " << intArray2 << "\n";

    try {
        std::cout << "Accessing a valid index: " << intArray[5] << "\n";
        std::cout << "Accessing an invalid index: " << intArray[SIZE] << "\n";
    }
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << "\n";
    }

    return 0;
}
