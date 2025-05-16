#include    "AAnimal.hpp"
#include    <iostream>

AAnimal::AAnimal() : type("AAnimal") {
    std::cout << "AAnimal is constructed" << std::endl;
}

AAnimal::~AAnimal() {
    std::cout << "AAnimal is destroyed" << std::endl;
}

AAnimal::AAnimal(const AAnimal& other) {
    type = other.type;
}

AAnimal& AAnimal::operator=(const AAnimal& other)
{
    if (this != &other)
        type = other.type;
    return *this;
}

std::string AAnimal::getType() const {
    return type;
}

void AAnimal::makeSound() const {
    std::cout << "Silence of none aanimal" << std::endl;
}