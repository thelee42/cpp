#include "Span.hpp"
#include <iostream>
#include <vector>
#include <cstdlib>  // rand()
#include <ctime>

int main() {
    std::srand(std::time(NULL));

    // 1. 기본 addNumber 테스트
    try {
        Span sp(5);
        sp.addNumber(5);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);
        std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest span: " << sp.longestSpan() << std::endl;

        try {
            sp.addNumber(42);
        } catch (const Span::NotEnoughSpaceException &e) {
            std::cout << "Expected exception: " << e.what() << std::endl;
        }
    } catch (const std::exception &e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

    std::cout << "----------------------" << std::endl;

    // 2. addRange 테스트
    try {
        Span sp2(10);
        std::vector<int> v;
        v.push_back(1);
        v.push_back(2);
        v.push_back(3);
        v.push_back(4);
        v.push_back(5);

        sp2.addRange(v);
        sp2.addNumber(10);
        sp2.addNumber(15);
        sp2.addNumber(20);
        sp2.addNumber(25);
        sp2.addNumber(30);

        std::cout << "Shortest span: " << sp2.shortestSpan() << std::endl;
        std::cout << "Longest span: " << sp2.longestSpan() << std::endl;

        std::vector<int> v2;
        v2.push_back(100);
        v2.push_back(200);
        try {
            sp2.addRange(v2);
        } catch (const Span::NotEnoughSpaceException &e) {
            std::cout << "Expected exception for addRange: " << e.what() << std::endl;
        }
    } catch (const std::exception &e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

    std::cout << "----------------------" << std::endl;

    // 3. 큰 데이터 테스트 (10,000개)
    try {
        const unsigned int N = 10000;
        Span spBig(N);
        std::vector<int> bigVec;
        for (unsigned int i = 0; i < N; ++i) {
            bigVec.push_back(std::rand() % 100000);
        }

        spBig.addRange(bigVec);
        std::cout << "Big vector test:" << std::endl;
        std::cout << "Shortest span: " << spBig.shortestSpan() << std::endl;
        std::cout << "Longest span: " << spBig.longestSpan() << std::endl;
    } catch (const std::exception &e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

    return 0;
}