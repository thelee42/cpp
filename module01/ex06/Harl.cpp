#include    "Harl.hpp"
#include    <iostream>

void Harl::debug()
{
    std::cout << "[ Debug ]\nI love having extra bacon." <<std::endl;
}

void Harl::info()
{
    std::cout << "[ Info ]\nI cannot believe adding extra bacon costs more money." <<std::endl;
}

void Harl::warning()
{
    std::cout << "[ Warning ]\nI think I deserve to have some extra bacon for free." <<std::endl;
}

void Harl::error()
{
    std::cout << "[ Error ]\nI want to speak to the manager now." <<std::endl;
}

Harl::Harl()
{
    complains[0] = &Harl::debug;
    complains[1] = &Harl::info;
    complains[2] = &Harl::warning;
    complains[3] = &Harl::error;
}

void Harl::complain(std::string level)
{
    std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    int i = 0;
    while (levels[i] != level && i < 4)
        i++;
    switch(i)
    {
        case 0:
            (this->*complains[0])();
        case 1:
            (this->*complains[1])();
        case 2:
            (this->*complains[2])();
        case 3:
            (this->*complains[3])();
            break;
        default:
            std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
    }
}