#include    "ScavTrap.hpp"
#include    <string>
#include    <iostream>

ScavTrap::ScavTrap() {
    Name = "noName";
    Hit = 100;
    Energy = 50;
    Attack = 20;
    std::cout << "ScavTrap " << Name << " is constructed" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
    Hit = 100;
    Energy = 50;
    Attack = 20;
    std::cout << "ScavTrap " << Name << " is ready to attack" << std::endl;
}

ScavTrap::~ScavTrap() {
    std::cout << "ScavTrap " << Name << " is destroyed" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other) {}

ScavTrap& ScavTrap::operator=(const ScavTrap& other)
{
    if (this != &other)
    {
        Name = other.Name;
        Hit = other.Hit;
        Energy = other.Energy;
        Attack = other.Attack;
    }
    return *this;
}

void ScavTrap::attack(const std::string &target)
{
    if (Energy <= 0)
    {
        std::cout << "ScavTrap " << Name << " has no energy to attack !" << std::endl;
        return ;
    }
    Energy -= 1;
    std::cout << "ScavTrap " << Name << " attacks " << target << ", causing " 
            << Attack << " points of damage!" << std::endl;
}

void ScavTrap::guardGate() {
    std::cout << "ScavTrap " << Name << " is now in Gate keeper mode." << std::endl;
}