#include    "Cat.hpp"
#include    <iostream>

Cat::Cat() {
    type = "Cat";
    brain = new Brain();
    std::cout << "Cat is constructed" << std::endl;
}
Cat::~Cat() {
    delete brain;
    std::cout << "Cat is destroyed" << std::endl;
}

//deep copy
Cat::Cat(const Cat& other) : AAnimal(other) {
    type = other.type;
    brain = new Brain (*other.brain);
}

Cat& Cat::operator=(const Cat& other) {
    if (this != &other)
    {
        type = other.type;
        if (brain)
            delete brain;
        brain = new Brain(*other.brain);
    }
    return *this;
}

void Cat::makeSound() const {
    std::cout << "meow" << std::endl;
}