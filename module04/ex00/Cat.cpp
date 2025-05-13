#include    "Cat.hpp"
#include    <iostream>

Cat::Cat() {
    type = "Cat";
    std::cout << "Cat is constructed" << std::endl;
}
Cat::~Cat() {
    std::cout << "Cat is destroyed" << std::endl;
}

//parent's copy must be called
Cat::Cat(const Cat& other) : Animal(other) {
    type = other.type;
}

Cat& Cat::operator=(const Cat& other) {
    if (this != &other)
        type = other.type;
    return *this;
}

void Cat::makeSound() const {
    std::cout << "meow" << std::endl;
}