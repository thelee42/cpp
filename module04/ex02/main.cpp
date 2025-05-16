#include <iostream>
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
    //AAnimal* aanimal = new AAnimal();
    
    std::cout << "===== Testing AAnimal, Dog, and Cat =====" << std::endl;
    AAnimal* dog = new Dog();  // Dog 객체 생성
    AAnimal* cat = new Cat();  // Cat 객체 생성

    // 동물의 소리 출력
    std::cout << "Dog says: ";
    dog->makeSound();  // "Woof!"
    
    std::cout << "Cat says: ";
    cat->makeSound();  // "Meow!"

    // 각 동물의 타입 출력
    std::cout << "Dog is of type: " << dog->getType() << std::endl;  // "Dog"
    std::cout << "Cat is of type: " << cat->getType() << std::endl;  // "Cat"

    // 메모리 해제
    delete dog;
    delete cat;

    std::cout << "\n===== Deep Copy Test =====" << std::endl;
    Dog original;
    Dog copy = original; // invokes deep copy constructor

    std::cout << "\nEnd of main - checking destructors" << std::endl;
    return 0;
}