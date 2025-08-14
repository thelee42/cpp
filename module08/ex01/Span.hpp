#ifndef Span_HPP
# define Span_HPP

#include <exception>
#include <vector>


class Span
{
    private:
        unsigned int maxSize;
        std::vector<int> numbers;
    public:
        Span();
        ~Span();
        Span(unsigned int N);
        Span(const Span& other);
        Span& operator=(const Span& other);

        void addNumber(int number);
        int shortestSpan() const;
        int longestSpan() const;
        void addRange(const std::vector<int> &v);
        class NoSpanException : public std::exception {
            public:
                const char *what() const throw();
        };
        class NotEnoughSpaceException : public std::exception {
            public:
                const char *what() const throw();
        };
};

#endif