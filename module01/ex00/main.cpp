#include    "Zombie.hpp"

int main()
{
    Zombie *zombie;

    randomChump("Zombie 1");
    zombie = newZombie("Zombie 2");
    zombie->announce();
    delete zombie;
    return 0;
}