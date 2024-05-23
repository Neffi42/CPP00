#pragma once

#include <ctime>
#include <vector>

#define THRESHOLD 2

class PmergeMe {
public:
    PmergeMe();
    PmergeMe(const PmergeMe& other);
    ~PmergeMe();

    const PmergeMe& operator=(const PmergeMe& other);

    static time_t mergeInsertionSortVector(std::vector<int>& v);
};
