#include    "DiamondTrap.hpp"
#include    "ScavTrap.hpp"
#include    "FragTrap.hpp"
#include    "ClapTrap.hpp"
#include    <iostream>

DiamondTrap::DiamondTrap() {
	Name = "noName";
	Hit = 100; //FragTrap::Hit;
    Energy = 50; //ScavTrap::Energy;
    Attack = 30; //FragTrap::Attack;
	std::cout << "DiamondTrap " << Name << " is constructed" << std::endl;
}


DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name), Name(name) {
	Hit = 100; //FragTrap::Hit;
    Energy = 50; //ScavTrap::Energy;
    Attack = 30; //FragTrap::Attack;
	std::cout << "DiamondTrap " << Name << " is ready to attack" << std::endl;
}


DiamondTrap::~DiamondTrap() {
    std::cout << "DiamondTrap " << Name << " is destroyed" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &other) : ClapTrap(other), ScavTrap(other), FragTrap(other) {
	Name = other.Name;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other) {
	if (this != &other)
	{
		ClapTrap::Name = other.ClapTrap::Name;
		Name = other.Name;
		Hit = other.Hit;
		Energy = other.Energy;
		Attack = other.Attack;
	}
	return *this;
}

void	DiamondTrap::attack(const std::string& target) {
	ScavTrap::attack(target);
}

void    DiamondTrap::whoAmI() {
    std::cout << "ClapTrap's name is " << ClapTrap::Name 
            << "\nDiamondTrap's name is " << DiamondTrap::Name << std::endl;
}