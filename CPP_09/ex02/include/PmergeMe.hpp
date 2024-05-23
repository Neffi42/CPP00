#pragma once

#include <ctime>
#include <deque>
#include <vector>

#define THRESHOLD 2

class PmergeMe {
public:
    PmergeMe();
    PmergeMe(const PmergeMe& other);
    ~PmergeMe();

    const PmergeMe& operator=(const PmergeMe& other);

    static time_t mergeInsertionSortVector(std::vector<int>& v);
    static time_t mergeInsertionSortDeque(std::deque<int>& d);
};

template<typename T>
int binarySearch(const T& v, int element) {
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

template<typename T>
void merge(T& pairs, T& arr1, T& arr2) {
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

template<typename T>
void mergeSort(T& pairs) {
    if (1 < pairs.size()) {
        T arr1(pairs.begin(), pairs.begin() + pairs.size() / 2);
        mergeSort(arr1);

        T arr2(pairs.begin() + pairs.size() / 2, pairs.end());
        mergeSort(arr2);

        merge(pairs, arr1, arr2);
    }
}

template<typename T>
T calculateGroupSizes(int totalElements) {
    T sizes;
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
