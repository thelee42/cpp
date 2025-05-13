#ifndef DiamondTrap_HPP
# define DiamondTrap_HPP

#include    <string>
#include    "ScavTrap.hpp"
#include    "FragTrap.hpp"


class DiamondTrap : public ScavTrap, public FragTrap
{
    private:
        std::string Name;
    public:
        DiamondTrap();
        ~DiamondTrap();
        DiamondTrap(std::string name);
        DiamondTrap(const DiamondTrap& other);
        DiamondTrap& operator=(const DiamondTrap& other);
        void attack(const std::string &target);
        void whoAmI();
};

#endif

//vitual inheritance : several inheritance from same grand parent