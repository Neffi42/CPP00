#include "PmergeMe.hpp"
#include <algorithm>
#include <cerrno>
#include <cstddef>
#include <cstdlib>
#include <ctime>
#include <deque>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

static std::string itos(int i) {
    std::stringstream ss;

    ss << i;
    return ss.str();
}

static void printVal(std::string key, std::vector<int>& v, std::deque<int>& d) {
    std::cout << key << ":\n";

    std::cout << "std::vector : ";
    for (std::vector<int>::iterator it = v.begin(); it != v.end(); it++) {
        std::cout << *it;
        if (it + 1 != v.end())
            std::cout << " ";
    }
    std::cout << "\n";

    std::cout << "std::deque : ";
    for (std::deque<int>::iterator it = d.begin(); it != d.end(); it++) {
        std::cout << *it;
        if (it + 1 != d.end())
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
    std::deque<int> d;
    int n;
    char *end = NULL;

    for (int i = 1; i < argc; i++) {
        n = strtol(argv[i], &end, 10);
        if (*end != '\0'
            || errno == ERANGE
            || argv[i] != itos(n)
            || n <= 0
            || std::find(v.begin(), v.end(), n) != v.end()) {
            std::cerr << "Error\n";
            return 1;
        }
        v.push_back(n);
        d.push_back(n);
    }

    printVal("Before", v, d);
    time_t timeV = PmergeMe::mergeInsertionSortVector(v);
    time_t timeD = PmergeMe::mergeInsertionSortDeque(d);
    printVal("After", v, d);
    printTime(v.size(), "vector", timeV);
    printTime(v.size(), "vector", timeD);

    return 0;
}
