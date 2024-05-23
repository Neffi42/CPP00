#include "PmergeMe.hpp"
#include <algorithm>
#include <cerrno>
#include <cstddef>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

static std::string itos(int i) {
    std::stringstream ss;

    ss << i;
    return ss.str();
}

static void printVal(std::string key, std::vector<int>& v) {
    std::cout << key << ":\n";
    std::cout << "std::vector : ";
    for (std::vector<int>::iterator it = v.begin(); it != v.end(); it++) {
        std::cout << *it;
        if (it + 1 != v.end())
            std::cout << " ";
    }
    std::cout << "\n";
}

static void printTime(size_t size, std::string container, time_t time) {
    std::cout << "Time to process a range of " << size << " elements with std::" << container << " : " << time << " us\n";
}

int main(int argc, char* argv[]) {
    if (argc < 3) {
        std::cerr << "Usage: ./PmergeMe <sequence of two or more positive intergers>\n";
        return 2;
    }

    std::vector<int> v;
    int num;
    char *end = NULL;

    for (int i = 1; i < argc; i++) {
        num = strtol(argv[i], &end, 10);
        if (*end != '\0'
            || errno == ERANGE
            || argv[i] != itos(num)
            || num <= 0
            || std::find(v.begin(), v.end(), num) != v.end()) {
            std::cerr << "Error\n";
            return 1;
        }
        v.push_back(num);
    }

    printVal("Before", v);
    time_t timeV = PmergeMe::mergeInsertionSortVector(v);

    printVal("After", v);
    printTime(v.size(), "vector", timeV);

    return 0;
}
