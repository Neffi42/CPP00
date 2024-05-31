#pragma once

#include <cstddef>

template <typename T, typename L, typename F>
void iter(T* array, const L &len, F f) {
	if (array == NULL || f == NULL || len < 0)
		return ;
    for (L i = 0; i < len; i++) {
        f(array[i]);
    }
}
