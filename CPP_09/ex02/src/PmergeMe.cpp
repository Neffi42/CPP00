#include "PmergeMe.hpp"
#include <cmath>
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

static std::vector<int> calculateGroupSizes(int totalElements) {
    std::vector<int> sizes;
    int i = 0, currentSize = 2, sum = 0;

    while (sum + currentSize <= totalElements) {
        sum += currentSize;
        sizes.push_back(currentSize);
        i++;
        if (i < 2)
            currentSize = sizes[i - 1];
        else
            currentSize = sizes[i - 2] * 2 + sizes[i - 1];
    }

    if (sum < totalElements) {
        sizes.push_back(totalElements - sum);
    }

    return sizes;
}

static int binarySearch(const std::vector<int>& v, int element) {
    int left = 0;
    int right = v.size();

    while (left < right) {
        int mid = left + (right - left) / 2;
        if (v[mid] < element) {
            left = mid + 1;
        }
        else {
            right = mid;
        }
    }

    return left;
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
    mergeSortVector(pairs);
    for (std::vector< std::pair<int, int> >::iterator it = pairs.begin(); it != pairs.end(); it++) {
        if (it == pairs.begin())
            v.push_back(it->first);
        v.push_back(it->second);
    }
    pairs.push_back(lastOdd);

    int currentIndex = 1, totalElements = pairs.size() - 1;
    std::vector< std::vector<int> > groups;
    std::vector<int> sizes = calculateGroupSizes(totalElements);

    for (std::vector<int>::iterator it = sizes.begin(); it != sizes.end(); it++) {
        int& size = *it;
        std::vector<int> group;
        for (int i = 0; i < size; i++) {
            group.push_back(pairs[currentIndex + size - 1 - i].first);
        }
        currentIndex += size;
        groups.push_back(group);
    }

    for (std::vector<std::vector<int> >::iterator groupIt = groups.begin(); groupIt != groups.end(); ++groupIt) {
        std::vector<int>& group = *groupIt;
        for (std::vector<int>::iterator elemIt = group.begin(); elemIt != group.end(); ++elemIt) {
            int y = *elemIt;
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
