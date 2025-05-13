#include    "Dog.hpp"
#include    <iostream>

Dog::Dog() {
    type = "Dog";
    std::cout << "Dog is constructed" << std::endl;
}
Dog::~Dog() {
    std::cout << "Dog is destroyed" << std::endl;
}

//parent's copy must be called
Dog::Dog(const Dog& other) : Animal(other) {
    type = other.type;
}

Dog& Dog::operator=(const Dog& other) {
    if (this != &other)
        type = other.type;
    return *this;
}

void Dog::makeSound() const {
    std::cout << "woof woof" << std::endl;
}