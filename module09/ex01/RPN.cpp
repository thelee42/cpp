#include "RPN.hpp"

RPN::RPN() : numbers() {}

RPN::~RPN() {}

RPN::RPN(const RPN& other) {
    numbers = other.numbers;
}

RPN& RPN::operator=(const RPN& other) {
    if (this != &other)
        numbers = other.numbers;
    return *this;
}

void RPN::pushNumber(int number) {
    if (number < 0 || number > 9)
        throw std::runtime_error("Number out of range");
    numbers.push(number);
}
void RPN::applyOperator(const std::string &token) {
    if (numbers.size() < 2)
        throw std::runtime_error("Not enough numbers in stack");
    int b = numbers.top();
    numbers.pop();
    int a = numbers.top();
    numbers.pop();
    int result;
    if (token == "+")
        result = a+ b;
    else if (token == "-")
        result = a - b;
    else if (token == "*")
        result = a * b;
    else if (token == "/") {
        if (b == 0)
            throw std::runtime_error("Division by zero");
        result = a / b;
    }
    numbers.push(result);
}

int RPN::getTop() const {
    if (numbers.empty())
        throw std::runtime_error("Stack is empty");
    return numbers.top();
}