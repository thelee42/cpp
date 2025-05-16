#include    "Dog.hpp"
#include    <iostream>

Dog::Dog() {
    type = "Dog";
    brain = new Brain();
    std::cout << "Dog is constructed" << std::endl;
}
Dog::~Dog() {
    delete brain;
    std::cout << "Dog is destroyed" << std::endl;
}

//deep copy
Dog::Dog(const Dog& other) : AAnimal(other) {
    type = other.type;
    brain = new Brain (*other.brain);
}


Dog& Dog::operator=(const Dog& other) {
    if (this != &other)
    {
        type = other.type;
        if (brain)
            delete brain;
        brain = new Brain(*other.brain);
    }
    return *this;
}

void Dog::makeSound() const {
    std::cout << "woof woof" << std::endl;
}