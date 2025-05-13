#include "DiamondTrap.hpp"
#include    <iostream>

#include "DiamondTrap.hpp"

int main() {

    std::cout << "===== Default Constructor Tests =====" << std::endl;
    DiamondTrap dia;

    std::cout << "===== Constructor Tests =====" << std::endl;
    DiamondTrap dia1("Dia1");

    std::cout << "\n===== Attack Tests =====" << std::endl;
    dia1.attack("Enemy1");
    dia1.takeDamage(30);
    dia1.beRepaired(20);

    std::cout << "\n===== whoAmI() Test =====" << std::endl;
    dia1.whoAmI();

    std::cout << "\n===== Copy Constructor Test =====" << std::endl;
    DiamondTrap dia2(dia1);
    dia2.whoAmI();

    std::cout << "\n===== Assignment Operator Test =====" << std::endl;
    DiamondTrap dia3("Temp");
    dia3 = dia1;
    dia3.whoAmI();

    std::cout << "\n===== Energy Exhaustion Test =====" << std::endl;
    for (int i = 0; i < 55; ++i) {
        dia1.attack("Training Dummy");
    }

    std::cout << "\n===== Multiple DiamondTraps =====" << std::endl;
    DiamondTrap alpha("Alpha");
    DiamondTrap beta("Beta");

    alpha.attack("Beta");
    beta.takeDamage(30);
    beta.beRepaired(10);

    alpha.whoAmI();
    beta.whoAmI();

    std::cout << "\n===== Destruction Begins =====" << std::endl;
    return 0;
}