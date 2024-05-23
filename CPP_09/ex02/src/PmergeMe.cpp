#include "PmergeMe.hpp"
#include <bits/types/struct_timeval.h>
#include <ctime>
#include <sys/time.h>
#include <vector>

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe& other) {
    *this = other;
}
PmergeMe::~PmergeMe() {}

const PmergeMe& PmergeMe::operator=(const PmergeMe& other) {
    (void)other;
    return *this;
}

time_t PmergeMe::sortVector(std::vector<int>& v) {
    struct timeval start;
    gettimeofday(&start, NULL);

    (void)v;

    struct timeval end;
    gettimeofday(&end, NULL);

    return (end.tv_sec * 1000000 + end.tv_usec) - (start.tv_sec * 1000000 + start.tv_usec);
}
