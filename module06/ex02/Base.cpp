#include    "Base.hpp"
#include    <ctime>
#include    <cstdlib>
#include    <iostream>

Base::~Base() {}

Base * generate() {
    srand(time(NULL));
    int r = rand() % 3;
    if (!r)
        return new A;
    else if (r == 1)
        return new B;
    else
        return new C;
}

void identify(Base* p) {
    if(dynamic_cast<A*>(p))
        std::cout << "A" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "B" << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "C" << std::endl;
    else
        std::cout << "Unknown type" << std::endl;
}
void identify(Base& p) {
    try {
        (void)dynamic_cast<A&>(p);
        std::cout << "A" << std::endl;
        return ;
    } catch (...) {};
    try {
        (void)dynamic_cast<B&>(p);
        std::cout << "B" << std::endl;
        return ;
    } catch (...) {};
    try {
        (void)dynamic_cast<C&>(p);
        std::cout << "C" << std::endl;
        return ;
    } catch (...) {};
    std::cout << "Unknown" << std::endl;
}

/* 
dynamic_cast<Derived*>(basePtr)
basePtr가 실제로 가리키는 객체가 Derived 타입이 맞으면, 해당 타입 포인터, 아니면 NULL
** type check && downcasting 
*/

// dynamic_cast : exception throw std::bad_cast
