#include "PmergeMe.hpp"
#include <cstddef>
#include <ctime>
#include <sys/time.h>
#include <utility>
#include <vector>
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

static void mergeVector(std::vector< std::pair<int, int> >& pairs, std::vector< std::pair<int, int> >& arr1, std::vector< std::pair<int, int> >& arr2) {
    pairs.clear();

    size_t i = 0, j = 0;
    while (i < arr1.size() && j < arr2.size()) {
        if(arr1.at(i).second <= arr2.at(j).second){
            pairs.push_back(arr1.at(i));
            i++;
        }
        else if(arr1.at(i).second > arr2.at(j).second){
            pairs.push_back(arr2.at(j));
            j++;
        }
    }

    while(i < arr1.size()){
        pairs.push_back(arr1.at(i));
        i++;
    }

    while(j < arr2.size()){
        pairs.push_back(arr2.at(j));
        j++;
    }
}

static void mergeSortVector(std::vector< std::pair<int, int> >& pairs) {
    if (1 < pairs.size()) {
        std::vector< std::pair<int, int> > arr1(pairs.begin(), pairs.begin() + pairs.size() / 2);
        mergeSortVector(arr1);

        std::vector< std::pair<int, int> > arr2(pairs.begin() + pairs.size() / 2, pairs.end());
        mergeSortVector(arr2);

        mergeVector(pairs, arr1, arr2);
    }
}

static void sortVector(std::vector<int>& v) {
    std::vector< std::pair<int, int> > pairs;
    pairs.resize(v.size() / 2 + 1);

    for (size_t i = 0; i < v.size(); i++) {
        if (i % 2 == 0)
            pairs[i / 2].first = v[i];
        else
            pairs[i / 2].second = v[i];
        if (i + 1 == v.size() && v.size() % 2)
            pairs[i / 2].second = 0;
    }

    v.clear();

    for (std::vector< std::pair<int, int> >::iterator it = pairs.begin(); it != pairs.end(); it++) {
        if (it->first > it->second)
            std::swap(it->first, it->second);
    }
    mergeSortVector(pairs);
    for (std::vector< std::pair<int, int> >::iterator it = pairs.begin(); it != pairs.end(); it++) {
        if (it == pairs.begin() && it->first != 0)
            v.push_back(it->first);
        v.push_back(it->second);
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
