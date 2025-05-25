#include    "Character.hpp"
#include    <iostream>

Character::Character() : _name("") {
    for (int i = 0; i < 4; i++) {
        Materias[i] = NULL;
    }
}

Character::Character(std::string name) : _name(name) {
    for (int i = 0; i < 4; i++) {
        Materias[i] = NULL;
    }
}

Character::~Character() {
    for (int i = 0; i < 4; i++) {
    delete Materias[i];
    Materias[i] = NULL;
    }
}

Character::Character(const Character& other) {
    _name = other._name;
    for (int i = 0; i < 4; i++) {
        if (other.Materias[i])
            Materias[i] = other.Materias[i]->clone();
        else
            Materias[i] = NULL;
    }
}

Character& Character::operator=(const Character& other) {
    if (this != &other) {
        _name = other._name;
        for (int i = 0; i < 4; i++) {
            delete Materias[i];
        }
        for (int i = 0; i < 4; i++) {
            Materias[i] = other.Materias[i]->clone();
        }
    }
    return *this;
}
std::string const& Character::getName() const {
    return _name;
}

void Character::equip(AMateria* m) {
    for(int i = 0; i < 4; i++) {
        if (!Materias[i]) {
            Materias[i] = m;
            return ;
        }
    }
}
void Character::unequip(int idx) {
    if (idx < 0 || idx >= 4)
        return ;
    Materias[idx] = NULL;
}

void Character::use(int idx, ICharacter& target) {
    if (idx < 0 || idx >= 4 || !Materias[idx])
        return ;
    Materias[idx]->use(target);
}