#include    "Zombie.hpp"

int main()
{
    int N;

    N = 9;
    Zombie *zombies = zombieHorde(N, "zebie n.");
    for (int i = 0; i < N; i++)
        zombies[i].announce();
    delete[] zombies;
    return 0;
}