#include    "WrongCat.hpp"
#include    <iostream>

WrongCat::WrongCat() {
    type = "WrongCat";
    std::cout << "WrongCat is constructed" << std::endl;
}
WrongCat::~WrongCat() {
    std::cout << "WrongCat is destroyed" << std::endl;
}

WrongCat::WrongCat(const WrongCat& other) : WrongAnimal(other) {
    type = other.type;
}

WrongCat& WrongCat::operator=(const WrongCat& other) {
    if (this != &other)
        type = other.type;
    return *this;
}
