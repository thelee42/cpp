#include <iostream>
#include <string>
#include <cctype> // std::toupper
#include "iter.hpp"

// ====== 출력 함수 ======
template <typename T>
void printElement(T &elem) {
    std::cout << elem << " ";
}

// ====== 수정 함수 ======
void incrementInt(int &x) { x += 10; }
void multiplyDouble(double &x) { x *= 1.5; }
void toUpperChar(char &c) { c = std::toupper(c); }
void appendExclamation(std::string &s) { s += "!"; }

// ====== 제곱 함수 ======
template <typename T>
void square(T &x) { x = x * x; }

int main() {
    // 1. int 배열
    int intArr[] = {1, 2, 3, 4, 5};
    size_t intLen = sizeof(intArr) / sizeof(intArr[0]);

    std::cout << "[INT TEST]" << std::endl;
    std::cout << "Original: ";
    iter(intArr, intLen, printElement<int>);
    std::cout << std::endl;

    iter(intArr, intLen, incrementInt);
    std::cout << "After increment (+10): ";
    iter(intArr, intLen, printElement<int>);
    std::cout << std::endl;

    iter(intArr, intLen, square<int>);
    std::cout << "After square: ";
    iter(intArr, intLen, printElement<int>);
    std::cout << "\n\n";

    // 2. double 배열
    double dblArr[] = {1.1, 2.2, 3.3};
    size_t dblLen = sizeof(dblArr) / sizeof(dblArr[0]);

    std::cout << "[DOUBLE TEST]" << std::endl;
    std::cout << "Original: ";
    iter(dblArr, dblLen, printElement<double>);
    std::cout << std::endl;

    iter(dblArr, dblLen, multiplyDouble);
    std::cout << "After multiply (x1.5): ";
    iter(dblArr, dblLen, printElement<double>);
    std::cout << std::endl;

    iter(dblArr, dblLen, square<double>);
    std::cout << "After square: ";
    iter(dblArr, dblLen, printElement<double>);
    std::cout << "\n\n";

    // 3. char 배열
    char charArr[] = {'a', 'b', 'c', 'd'};
    size_t charLen = sizeof(charArr) / sizeof(charArr[0]);

    std::cout << "[CHAR TEST]" << std::endl;
    std::cout << "Original: ";
    iter(charArr, charLen, printElement<char>);
    std::cout << std::endl;

    iter(charArr, charLen, toUpperChar);
    std::cout << "After toUpper: ";
    iter(charArr, charLen, printElement<char>);
    std::cout << "\n\n";

    // 4. string 배열
    std::string strArr[] = {"hello", "cpp", "templates"};
    size_t strLen = sizeof(strArr) / sizeof(strArr[0]);

    std::cout << "[STRING TEST]" << std::endl;
    std::cout << "Original: ";
    iter(strArr, strLen, printElement<std::string>);
    std::cout << std::endl;

    iter(strArr, strLen, appendExclamation);
    std::cout << "After append '!': ";
    iter(strArr, strLen, printElement<std::string>);
    std::cout << std::endl;

    return 0;
}