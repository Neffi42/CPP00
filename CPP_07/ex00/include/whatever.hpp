#pragma once

template <typename T>
void swap(T& x, T& y) {
    T tmp = x;
    x = y;
    y = tmp;
}

template <typename T>
T max(const T& x, const T& y) {
    return x > y ? x : y;
}

template <typename T>
T min(const T& x, const T& y) {
    return x < y ? x : y;
}
