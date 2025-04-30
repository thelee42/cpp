#ifndef ClapTrap_HPP
# define ClapTrap_HPP

#include    <string>

class ClapTrap
{
    private:
        std::string Name;
        unsigned int Hit;
        unsigned int Energy;
        unsigned int Attack;

    public:
        ClapTrap(std::string name);
        ~ClapTrap();
        ClapTrap(const ClapTrap& other);
        ClapTrap& operator=(const ClapTrap& other);
        void attack(const std::string &target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);
};

#endif