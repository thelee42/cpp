#include    "Animal.hpp"
#include    "Dog.hpp"
#include    "Cat.hpp"
#include    "WrongAnimal.hpp"
#include    "WrongCat.hpp"
#include    <iostream>

// int main()
// {
//     const Animal* meta = new Animal();
//     const Animal* j = new Dog();
//     const Animal* i = new Cat();
//     std::cout << j->getType() << " " << std::endl;
//     std::cout << i->getType() << " " << std::endl;
//     i->makeSound();
//     j->makeSound();
//     meta->makeSound();

//     delete meta;
//     delete j;
//     delete i;

//     return 0;
// }

void separator(const std::string &title) {
    std::cout << "\n==== " << title << " ====\n" << std::endl;
}

int main() {
    separator("Basic Object Creation");

    const Animal* meta = new Animal();
    const Animal* dog = new Dog();
    const Animal* cat = new Cat();

    separator("Type & Sound Check (Virtual Functions)");

    std::cout << "Type of dog: " << dog->getType() << std::endl;
    std::cout << "Type of cat: " << cat->getType() << std::endl;
    std::cout << "Dog sound: "; dog->makeSound();  // Should bark
    std::cout << "Cat sound: "; cat->makeSound();  // Should meow
    std::cout << "Animal sound: "; meta->makeSound(); // Should generic

    separator("WrongAnimal Test (No Virtual Function)");

    const WrongAnimal* wrongMeta = new WrongAnimal();
    const WrongAnimal* wrongCat = new WrongCat();

    std::cout << "Type of wrongCat: " << wrongCat->getType() << std::endl;
    std::cout << "WrongAnimal sound: "; wrongMeta->makeSound();
    std::cout << "WrongCat sound : "; wrongCat->makeSound();

    separator("Copy Constructor Test");

    Dog dog1;
    Dog dog2(dog1);

    Cat cat1;
    Cat cat2(cat1);

    separator("Assignment Operator Test");

    Dog dog3;
    dog3 = dog1;

    Cat cat3;
    cat3 = cat1;

    separator("Destruction (Expect Reverse Order)");

    delete meta;
    delete dog;
    delete cat;

    delete wrongMeta;
    delete wrongCat;

    separator("Stack Object Destruction");

    {
        Dog localDog;
        Cat localCat;
        Animal localAnimal;
    }

    separator("Polymorphism Test with Array");

    const Animal* zoo[4];
    zoo[0] = new Dog();
    zoo[1] = new Cat();
    zoo[2] = new Dog();
    zoo[3] = new Cat();

    for (int i = 0; i < 4; ++i) {
        std::cout << "[" << i << "] " << zoo[i]->getType() << ": ";
        zoo[i]->makeSound();
    }

    for (int i = 0; i < 4; ++i) {
        delete zoo[i];
    }

    separator("End of Tests");

    return 0;
}