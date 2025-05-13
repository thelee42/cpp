#include    "WrongAnimal.hpp"
#include    <iostream>

WrongAnimal::WrongAnimal() : type("WrongAnimal") {
    std::cout << "WrongAnimal is constructed" << std::endl;
}

WrongAnimal::~WrongAnimal() {
    std::cout << "WrongAnimal is destroyed" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& other) {
    type = other.type;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other)
{
    if (this != &other)
        type = other.type;
    return *this;
}

std::string WrongAnimal::getType() const {
    return type;
}

void WrongAnimal::makeSound() const {
    std::cout << "Silence of none animal" << std::endl;
}