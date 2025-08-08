#include    "Array.hpp"

template <typename T>
Array<T>::Array() : elements(nullptr), length(0) {}

template <typename T>
Array<T>::~Array() {
    delete[] elements;
}

template <typename T>
Array<T>::Array(unsigned int n) : elements(nullptr), length(n) {
    if (n > 0)
        elements = new T[n]();
}

template <typename T>
Array<T>::Array(const Array &other) : elements(nullptr), length(other.length) {
    if (length > 0) {
        elements = new T[length];
        for (unsigned int i = 0; i < other.length; i++) {
            elements[i] = other.elements[i];
        }
    }
}

template <typename T>
Array<T> &Array<T>::operator=(const Array &other) {
    if (this != &other) {
        delete[] elements;
        length = other.length;
        elements = nullptr;
        if (length > 0) {
            elements = new T[length];
            for (size_t i = 0; i < length; ++i) {
            elements[i] = other.elements[i];
            }
        }
    }
    return *this;
}

template <typename T>
T &Array<T>::operator[](unsigned int index) {
    if (index >= length) {
        throw OutOfBoundsException();
    }
    return elements[index];
}

template <typename T>
const char *Array<T>::OutOfBoundsException::what() const throw() {
    return "Out of bounds access in Array";
}

template <typename T>
size_t Array<T>::size() const {
    return length;
}