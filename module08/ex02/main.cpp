#include "MutantStack.hpp"
#include <iostream>
#include <list>

void printStack(const MutantStack<int>& mstack) {
    std::cout << "Forward iteration: ";
    for(MutantStack<int>::const_iterator it = mstack.begin(); it != mstack.end(); ++it)
        std::cout << *it << " ";
    std::cout << "\n";

    std::cout << "Reverse iteration: ";
    for(MutantStack<int>::const_reverse_iterator rit = mstack.rbegin(); rit != mstack.rend(); ++rit)
        std::cout << *rit << " ";
    std::cout << "\n";
}

void printList(const std::list<int>& lst) {
    std::cout << "Forward iteration: ";
    for(std::list<int>::const_iterator it = lst.begin(); it != lst.end(); ++it)
        std::cout << *it << " ";
    std::cout << "\n";

    std::cout << "Reverse iteration: ";
    for(std::list<int>::const_reverse_iterator rit = lst.rbegin(); rit != lst.rend(); ++rit)
        std::cout << *rit << " ";
    std::cout << "\n";
}

int main() {
    std::cout << "=== MutantStack Test ===\n";
    MutantStack<int> mstack;
    for(int i = 1; i <= 5; ++i)
        mstack.push(i);
    printStack(mstack);

    std::cout << "=== std::list Test ===\n";
    std::list<int> lst;
    for(int i = 1; i <= 5; ++i)
        lst.push_back(i);
    printList(lst);

    return 0;
}