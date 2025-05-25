#include    "Cure.hpp"
#include    <iostream>

Cure::Cure() : AMateria() {
    type = "cure";
}

Cure::~Cure() {}

Cure::Cure(const Cure& other) : AMateria(other) {
    type = other.type;
}

Cure& Cure::operator=(const Cure& other) {
    if (this != &other)
        type = other.type;
    return *this;
}

AMateria* Cure::clone() const {
    return new Cure(*this);
}

void Cure::use(ICharacter& target) {
    std::cout << "* heals " << target.getName() << "`s wounds *" << std::endl;
}