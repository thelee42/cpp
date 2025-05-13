#ifndef ScavTrap_HPP
# define ScavTrap_HPP

#include    "ClapTrap.hpp"
#include    <string>

class ScavTrap : public ClapTrap
{
    public:
        ScavTrap();
        ~ScavTrap();
        ScavTrap(std::string name);
        ScavTrap(const ScavTrap& other);
        ScavTrap& operator=(const ScavTrap& other);
        void attack(const std::string &target);
        void guardGate();
};

#endif

// public 상속: 부모 클래스를 자식 클래스가 확장하며 부모 클래스의 인터페이스를 그대로 사용하는 경우
// protected 상속: 부모 클래스의 인터페이스는 숨기고 자식 클래스 내에서만 사용하는 경우
// private 상속: 부모 클래스의 구현을 완전히 감추고 자식 클래스에서만 사용하는 경우