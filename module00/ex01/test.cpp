#include <iostream>
#include <iomanip>  // std::setw

int main() 
{
    while (1)
    {
        std::cout << "type a text\n";
        std::string str;
        std::getline(std::cin, str);
        if (str.length() > 10)
            std::cout << std::setw(10) << str.substr(0, 9) + "." << std::endl;
        else
            std::cout << std::setw(10) << str << std::endl;
    }
    return 0;
}