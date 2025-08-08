#ifndef ITER_HPP
#define ITER_HPP

#include <cstddef> // size_t


template <typename T>
void iter(T *array, size_t length, void (*func)(T &)) {
    if (!array || length == 0 || !func) {
        return;
    }   
    for (size_t i = 0; i < length; i++) {
        func(array[i]);
    }
}

#endif

/* 
(*func) → pointer of user-defined function
    in c++98, you only can call the function pointer.
(const T &) → that function takes a const T type reference as an argument
 */