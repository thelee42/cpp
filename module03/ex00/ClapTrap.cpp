#include    "ClapTrap.hpp"
#include    <iostream>


ClapTrap::ClapTrap(std::string name) : Name(name), Hit(10), Energy(10), Attack(0) {
    std::cout << "ClapTrap " << Name << " is ready to attack" << std::endl;
}

ClapTrap::~ClapTrap() {
    std::cout << "ClapTrap " << Name << " is destroyed" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other)
{
    *this = other;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other)
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

void ClapTrap::attack(const std::string &target)
{
    if (Energy <= 0)
    {
        std::cout << "ClapTrap " << Name << " has no energy to attack !" << std::endl;
        return ;
    }
    Energy -= 1;
    std::cout << "ClapTrap " << Name << " attacks " << target << ", causing " 
            << Attack << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if (Hit >= amount)
        Hit -= amount;
    else
        Hit = 0;
    std::cout << "ClapTrap " << Name << " takes " << amount
            << " damage. Current HP : " << Hit << std::endl;
}
void ClapTrap::beRepaired(unsigned int amount)
{
    if (Energy <= 0)
    {
        std::cout << "ClapTrap " << Name << " has no energy to repair !" << std::endl;
        return ;
    }
    Energy -= 1;
    Hit += amount;
    std::cout << "ClapTrap " << Name << " has been repaired by " << amount 
            << ". Current HP : " << Hit << std::endl;
}

