#include    "AMateria.hpp"
#include    <iostream>
#include    <string>

AMateria::AMateria() : type("") {}

AMateria::~AMateria() {}

AMateria::AMateria(const AMateria& other) {
    type = other.type;
}

AMateria& AMateria::operator=(const AMateria& other) {
    if (this != &other)
        type = other.type;
    return *this;
}

AMateria::AMateria(std::string const &type) : type(type) {}

std::string const& AMateria::getType() const {
    return (type);
}

void AMateria::use(ICharacter& target) {
    std::cout << "AMateria " << type << "is used on " << target.getName() << std::endl;
}