#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <exception>

template <typename T>
class Array {
    private: 
        T *elements;
        size_t length;
    public:
        Array();
        ~Array();
        Array(unsigned int n);
        Array(const Array &other);
        Array &operator=(const Array &other);
        T &operator[](unsigned int index);
        class OutOfBoundsException : public std::exception {
            public :
                const char *what() const throw();
        };
       size_t size() const;
};
#include "Array.tpp"

#endif