#include "easyfind.hpp"
#include <exception>
#include <iostream>
#include <list>
#include <vector>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        return 1;
    }

    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    std::vector<int> vect(arr, arr + sizeof(arr) / sizeof(int));
    std::list<int> li(arr, arr + sizeof(arr) / sizeof(int));

    try {
        easyfind(vect, std::atoi(argv[1]));
    } catch (const std::exception& e) {
        std::cerr << e.what() << "\n";
    }

    try {
        easyfind(li, std::atoi(argv[1]));
    } catch (const std::exception& e) {
        std::cerr << e.what() << "\n";
    }

    return 0;
}
