#ifndef UTILS_HPP
#define UTILS_HPP

template <typename T>
void swap(T &a, T &b) {
    T tmp = a;
    a = b;
    b = tmp;
}

template <typename T>
T min(const T &a, const T &b) {
    return (a < b) ? a : b;
}

template <typename T>
T max(const T &a, const T &b) {
    return (a > b) ? a : b;
}

#endif


/* 
Template : funtions or classes independant of type.
- define must be in .hpp
- or .tpp 
    #include "template.tpp" before #endif in .hpp

define : 
template <typename T>
 */