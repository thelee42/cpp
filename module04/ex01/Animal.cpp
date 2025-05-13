#include    "Animal.hpp"
#include    <iostream>

Animal::Animal() : type("Animal") {
    std::cout << "Animal is constructed" << std::endl;
}

Animal::~Animal() {
    std::cout << "Animal is destroyed" << std::endl;
}

Animal::Animal(const Animal& other) {
    type = other.type;
}

Animal& Animal::operator=(const Animal& other)
{
    if (this != &other)
        type = other.type;
    return *this;
}

std::string Animal::getType() const {
    return type;
}

void Animal::makeSound() const {
    std::cout << "Silence of none animal" << std::endl;
}