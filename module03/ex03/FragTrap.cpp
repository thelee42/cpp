#include    "FragTrap.hpp"
#include    <iostream>

FragTrap::FragTrap() {
	Name = "noName";
    Hit = 100;
    Energy = 100;
    Attack = 30;
	std::cout << "FragTrap " << Name << " is constructed" << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name) {
    Hit = 100;
    Energy = 100;
    Attack = 30;
    std::cout << "FragTrap " << Name << " is ready to attack" << std::endl;
}

FragTrap::~FragTrap() {
    std::cout << "FragTrap " << Name << " is destroyed" << std::endl;
}

FragTrap::FragTrap(const FragTrap &other) : ClapTrap(other) {}

FragTrap& FragTrap::operator=(const FragTrap& other) {
	if (this != &other)
	{
		Name = other.Name;
		Hit = other.Hit;
		Energy = other.Energy;
		Attack = other.Attack;
	}
	return *this;
}

void    FragTrap::highFivesGuys() {
	std::cout << "Good Job ! Give yourself a virtual high-five! ✋" << std::endl;
}