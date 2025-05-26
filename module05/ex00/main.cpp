#include "Bureaucrat.hpp"
#include <iostream>

int main() {
    try {
        Bureaucrat b1("Alice", 42);
        std::cout << b1 << std::endl;

        b1.imcrementGrade();
        std::cout << "After increment: " << b1 << std::endl;

        b1.decrementGrade();
        b1.decrementGrade();
        std::cout << "After two decrements: " << b1 << std::endl;

        // 잘못된 생성 시도: 높은 등급
        Bureaucrat b2("Bob", 0);
    }
    catch (std::exception &e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    try {
        // 잘못된 생성 시도: 낮은 등급
        Bureaucrat b3("Charlie", 151);
    }
    catch (std::exception &e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    try {
        Bureaucrat b4("David", 1);
        std::cout << b4 << std::endl;

        // 너무 높은 등급으로 증강 시도
        b4.imcrementGrade();
    }
    catch (std::exception &e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    try {
        Bureaucrat b5("Eve", 150);
        std::cout << b5 << std::endl;

        // 너무 낮은 등급으로 감소 시도
        b5.decrementGrade();
    }
    catch (std::exception &e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    return 0;
}

//중첩클래스
//std::expection