#include <iostream>
#include <vector>
#include <list>
#include "easyfind.hpp"

int main() {
    try {
        // ===== VECTOR 테스트 =====
        std::vector<int> vec;
        for(int i=0; i<10; i++) vec.push_back(i);

        std::cout << "Testing vector<int>:" << std::endl;

        // 존재하는 값
        std::vector<int>::iterator it1 = easyfind(vec, 5);
        std::cout << "Found 5 in vector: " << *it1 << std::endl;

        // 존재하지 않는 값
        try {
            std::vector<int>::iterator it2 = easyfind(vec, 42);
            std::cout << "Found 42 in vector: " << *it2 << std::endl;
        } catch(const std::exception &e) {
            std::cout << "Vector test 42: " << e.what() << std::endl;
        }

        // ===== LIST 테스트 =====
        std::list<int> lst;
        for(int i=10; i<20; i++) lst.push_back(i);

        std::cout << "\nTesting list<int>:" << std::endl;

        // 존재하는 값
        std::list<int>::iterator it3 = easyfind(lst, 15);
        std::cout << "Found 15 in list: " << *it3 << std::endl;

        // 존재하지 않는 값
        try {
            std::list<int>::iterator it4 = easyfind(lst, 99);
            std::cout << "Found 99 in list: " << *it4 << std::endl;
        } catch(const std::exception &e) {
            std::cout << "List test 99: " << e.what() << std::endl;
        }

        // ===== 임시값/리터럴 테스트 =====
        std::cout << "\nTesting with literals:" << std::endl;
        std::vector<int>::iterator it5 = easyfind(vec, 7);
        std::cout << "Found 7 in vector: " << *it5 << std::endl;

    } catch(const std::exception &e) {
        std::cout << "Unexpected exception: " << e.what() << std::endl;
    }

    return 0;
}