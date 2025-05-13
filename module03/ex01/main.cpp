#include <iostream>
#include "ScavTrap.hpp"

int main() {
    // ScavTrap 객체 생성 (기본 생성자)
    ScavTrap scav("ScavTrap-default");

    ScavTrap scav1("ScavTrap1");
    // ScavTrap 객체 복사 생성자 테스트
    
    ScavTrap scav9("ScavTrap9");

    // ScavTrap 객체의 guardGate 호출
    scav1.guardGate();

    // ScavTrap 객체의 attack 호출
    scav1.attack("ScavTrap9");

    // ScavTrap 객체의 takeDamage 호출
    scav9.takeDamage(20);

    ScavTrap scav2(scav9);

    // ScavTrap 객체의 beRepaired 호출
    scav2.beRepaired(10);

    return 0;
}