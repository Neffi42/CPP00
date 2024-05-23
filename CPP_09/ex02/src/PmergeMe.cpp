#include "PmergeMe.hpp"
#include <cmath>
#include <cstddef>
#include <ctime>
#include <sys/time.h>
#include <utility>
#include <vector>
#include <deque>
#include <algorithm>

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe& other) {
    *this = other;
}
PmergeMe::~PmergeMe() {}

const PmergeMe& PmergeMe::operator=(const PmergeMe& other) {
    (void)other;
    return *this;
}

static void sortVector(std::vector<int>& v) {
    bool isOdd = v.size() % 2;
    std::pair<int, int> lastOdd;
    std::vector< std::pair<int, int> > pairs;

    pairs.resize(v.size() / 2);
    for (size_t i = 0; i < v.size(); i++) {
        if (isOdd && i + 1 == v.size()) {
            lastOdd.first = v[i];
            lastOdd.second = 0;
        }
        else if (i % 2 == 0)
            pairs[i / 2].first = v[i];
        else
            pairs[i / 2].second = v[i];
    }

    v.clear();
    for (std::vector< std::pair<int, int> >::iterator it = pairs.begin(); it != pairs.end(); it++) {
        if (it->first > it->second && it->second != 0)
            std::swap(it->first, it->second);
    }
    mergeSort(pairs);
    for (std::vector< std::pair<int, int> >::iterator it = pairs.begin(); it != pairs.end(); it++) {
        if (it == pairs.begin())
            v.push_back(it->first);
        v.push_back(it->second);
    }
    if (isOdd)
        pairs.push_back(lastOdd);

    int currentIndex = 1, totalElements = pairs.size() - 1;
    std::vector< std::vector<int> > groups;
    std::vector<int> sizes = calculateGroupSizes<std::vector<int> >(totalElements);

    for (std::vector<int>::iterator it = sizes.begin(); it != sizes.end(); it++) {
        int& size = *it;
        std::vector<int> group;
        for (int i = 0; i < size; i++) {
            group.push_back(pairs[currentIndex + size - 1 - i].first);
        }
        currentIndex += size;
        groups.push_back(group);
    }

    for (std::vector<std::vector<int> >::iterator it = groups.begin(); it != groups.end(); ++it) {
        std::vector<int>& group = *it;
        for (std::vector<int>::iterator elId = group.begin(); elId != group.end(); ++elId) {
            int y = *elId;
            int pos = binarySearch(v, y);
            v.insert(v.begin() + pos, y);
        }
    }
}

time_t PmergeMe::mergeInsertionSortVector(std::vector<int>& v) {
    struct timeval start;
    gettimeofday(&start, NULL);

    sortVector(v);

    struct timeval end;
    gettimeofday(&end, NULL);

    return (end.tv_sec * 1000000 + end.tv_usec) - (start.tv_sec * 1000000 + start.tv_usec);
}

static void sortDeque(std::deque<int>& d) {
    bool isOdd = d.size() % 2;
    std::pair<int, int> lastOdd;
    std::deque< std::pair<int, int> > pairs;

    pairs.resize(d.size() / 2);
    for (size_t i = 0; i < d.size(); i++) {
        if (isOdd && i + 1 == d.size()) {
            lastOdd.first = d[i];
            lastOdd.second = 0;
        }
        else if (i % 2 == 0)
            pairs[i / 2].first = d[i];
        else
            pairs[i / 2].second = d[i];
    }

    d.clear();
    for (std::deque< std::pair<int, int> >::iterator it = pairs.begin(); it != pairs.end(); it++) {
        if (it->first > it->second && it->second != 0)
            std::swap(it->first, it->second);
    }
    mergeSort(pairs);
    for (std::deque< std::pair<int, int> >::iterator it = pairs.begin(); it != pairs.end(); it++) {
        if (it == pairs.begin())
            d.push_back(it->first);
        d.push_back(it->second);
    }
    if (isOdd)
        pairs.push_back(lastOdd);

    int currentIndex = 1, totalElements = pairs.size() - 1;
    std::deque< std::deque<int> > groups;
    std::deque<int> sizes = calculateGroupSizes<std::deque<int> >(totalElements);

    for (std::deque<int>::iterator it = sizes.begin(); it != sizes.end(); it++) {
        int& size = *it;
        std::deque<int> group;
        for (int i = 0; i < size; i++) {
            group.push_back(pairs[currentIndex + size - 1 - i].first);
        }
        currentIndex += size;
        groups.push_back(group);
    }

    for (std::deque<std::deque<int> >::iterator it = groups.begin(); it != groups.end(); ++it) {
        std::deque<int>& group = *it;
        for (std::deque<int>::iterator elId = group.begin(); elId != group.end(); ++elId) {
            int y = *elId;
            int pos = binarySearch(d, y);
            d.insert(d.begin() + pos, y);
        }
    }
}

time_t PmergeMe::mergeInsertionSortDeque(std::deque<int>& d) {
    struct timeval start;
    gettimeofday(&start, NULL);

    sortDeque(d);

    struct timeval end;
    gettimeofday(&end, NULL);

    return (end.tv_sec * 1000000 + end.tv_usec) - (start.tv_sec * 1000000 + start.tv_usec);
}
