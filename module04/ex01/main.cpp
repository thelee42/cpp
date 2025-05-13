#include <iostream>
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
    std::cout << "===== Constructing via Animal pointer =====" << std::endl;
    const Animal* j = new Dog();
    const Animal* i = new Cat();

    std::cout << "\n===== Making Sound =====" << std::endl;
    j->makeSound(); // should output: Woof!
    i->makeSound(); // should output: Meow!

    std::cout << "\n===== Deleting via Animal pointer =====" << std::endl;
    delete j; // should call Dog's and Brain's destructor
    delete i; // should call Cat's and Brain's destructor

    std::cout << "\n===== Deep Copy Test =====" << std::endl;
    Dog original;
    Dog copy = original; // invokes deep copy constructor

    std::cout << "\nEnd of main - checking destructors" << std::endl;
    return 0;
}