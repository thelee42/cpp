#include    "Brain.hpp"
#include    <iostream>

Brain::Brain() {
    for (int i = 0; i < 100; i++)
        ideas[i] = "";
    std::cout << "Brain has been constructed" << std::endl;
}
Brain::~Brain() {
    std::cout << "Brain has been destroyed" << std::endl;
}
Brain::Brain(const Brain& other) {
    for (int i = 0; i < 100; i++)
        ideas[i] = other.ideas[i];
}
Brain& Brain::operator=(const Brain& other) {
    if (this != &other)
    {
        for (int i = 0; i < 100; i++)
            ideas[i] = other.ideas[i];
    }
    return *this;
}