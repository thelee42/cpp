#include "FragTrap.hpp"
#include    <iostream>

int main() {
    FragTrap frag("Fraggy");
    frag.attack("target dummy");
    frag.takeDamage(30);
    frag.beRepaired(20);
    frag.highFivesGuys();
    return 0;
}