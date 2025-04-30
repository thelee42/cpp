#include "ClapTrap.hpp"
#include <iostream>

int main()
{
    ClapTrap a("Alpha");
    ClapTrap b("Bravo");

    std::cout << "\n--- Round 1 ---" << std::endl;
    a.attack("Bravo");
    b.takeDamage(0);

    std::cout << "\n--- Round 2 ---" << std::endl;
    b.attack("Alpha");
    a.takeDamage(7);

    std::cout << "\n--- Round 3 ---" << std::endl;
    a.beRepaired(4);
    b.beRepaired(10);

    std::cout << "\n--- Exhaustion Test ---" << std::endl;
    for (int i = 0; i < 11; ++i)
        a.attack("Bravo");

    std::cout << "\n--- Final Blow ---" << std::endl;
    b.takeDamage(100);

    return 0;
}