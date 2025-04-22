#include    "Harl.hpp"
#include    <iostream>

int main(int ac, char **argv)
{
    if (ac != 2)
    {
        std::cerr << "[ Complaining about insignificant argument ]" << std::endl;
        return 1;
    }
    Harl harl;

    harl.complain(argv[1]);
    return 0;
}