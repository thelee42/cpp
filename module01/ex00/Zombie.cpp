#include    <iostream>
#include    "Zombie.hpp"

Zombie::Zombie(std::string in_name)
{
    name = in_name;
    std::cout << name << " is created" << std::endl;
}

Zombie::~Zombie()
{
    std::cout << name << " is eliminated" << std::endl;
}

void    Zombie::announce()
{
    std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}