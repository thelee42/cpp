#include    "Weapon.hpp"
#include    "HumanA.hpp"
#include    "HumanB.hpp"

int main()
{
    {
        Weapon club = Weapon("groza");
        HumanA bob("Bob", club);
        bob.attack();
        club.setType("M416");
        bob.attack();
    }
    {
        Weapon club = Weapon("AUG");
        HumanB jim("Jim");
        jim.setWeapon(club);
        jim.attack();
        club.setType("AKM");
        jim.attack();
    }
    return 0;
}