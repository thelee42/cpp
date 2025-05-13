#ifndef ClapTrap_HPP
# define ClapTrap_HPP

#include    <string>

class ClapTrap
{
    protected:
        std::string Name;
        unsigned int Hit;
        unsigned int Energy;
        unsigned int Attack;

    public:
        ClapTrap();
        ~ClapTrap();
        ClapTrap(std::string name);
        ClapTrap(const ClapTrap& other);
        ClapTrap& operator=(const ClapTrap& other);
        void attack(const std::string &target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);
};

#endif

//protected: protected로 선언된 멤버는 자식 클래스에서도 직접 접근할 수 있습니다. 
//          즉, 자식 클래스에서는 부모 클래스의 protected 멤버를 자유롭게 사용할 수 있습니다.