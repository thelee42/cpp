#include    <iostream>

int main()
{
    int a = 10;
    int *ptr = &a;
    int &ref = a;

    std::cout << a << std::endl;
    std::cout << *ptr << std::endl;
    std::cout << ref << std::endl;


    std::cout << &a << std::endl;
    std::cout << ptr << std::endl;
    std::cout << &ref << std::endl;
}

