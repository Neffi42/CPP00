#pragma once

#include <ctime>
#include <vector>

class PmergeMe {
public:
    PmergeMe();
    PmergeMe(const PmergeMe& other);
    ~PmergeMe();

    const PmergeMe& operator=(const PmergeMe& other);

    static time_t sortVector(std::vector<int>& v);
};
