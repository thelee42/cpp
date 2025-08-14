#include "Span.hpp"
#include <algorithm>

const char *Span::NoSpanException::what() const throw() {
    return "Not enough numbers to calculate span";
}

const char *Span::NotEnoughSpaceException::what() const throw() {
    return "Not enough space to add more numbers";
}

Span::Span() : maxSize(0) {}

Span::~Span() {}

Span::Span(unsigned int N) : maxSize(N) {}

Span::Span(const Span& other) : maxSize(other.maxSize), numbers(other.numbers) {}

Span& Span::operator=(const Span& other) {
    if(this != &other) {
        maxSize = other.maxSize;
        numbers = other.numbers;
    }
    return *this;
}

void Span::addNumber(int number) {
    if(numbers.size() >= maxSize)
        throw NotEnoughSpaceException();
    numbers.push_back(number);
}

void Span::addRange(const std::vector<int> &v) {
    if(numbers.size() + v.size() > maxSize)
        throw NotEnoughSpaceException();
    numbers.insert(numbers.end(), v.begin(), v.end());
}

int Span::shortestSpan() const {
    if (numbers.size() < 2)
        throw NoSpanException();
    if (numbers.size() == 2)
        return std::abs(numbers[0] - numbers[1]);
    std::vector<int> sorted = numbers;
    std::sort(sorted.begin(), sorted.end());
    int minSpan = sorted[1] - sorted[0];
    for (size_t i = 1; i < sorted.size() - 1; i++) {
        int span = sorted[i + 1] - sorted[i];
        if (span < minSpan)
            minSpan = span;
    }
    return minSpan;

}
int Span::longestSpan() const {
    if (numbers.size() < 2)
        throw NoSpanException();
    if (numbers.size() == 2)
        return std::abs(numbers[0] - numbers[1]);
    std::vector<int>::const_iterator minIt, maxIt;
    minIt = std::min_element(numbers.begin(), numbers.end());
    maxIt = std::max_element(numbers.begin(), numbers.end());
    return std::abs(*maxIt - *minIt);
}