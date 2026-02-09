#include    "RPN.hpp"
#include    <iostream>
#include    <sstream>

int main(int ac, char **av)
{
    if (ac != 2)
    {
        std::cerr << "Error: need one argument" << std::endl;
        return 1;
    }
    std::string input = av[1];
    std::string accepted = "0123456789+-*/ ";
    if (input.find_first_not_of(accepted) != std::string::npos)
    {
        std::cerr << "Error: invalid character" << std::endl;
        return 1;
    }
    RPN rpn;
    std::istringstream iss(input);
    std::string token;
    try {
        while (iss >> token)
        {
            if (token == "+" || token == "-" || token == "*" || token == "/")
                rpn.applyOperator(token);
            else
            {
                int number = std::stoi(token);
                rpn.pushNumber(number);
            }
        }
    }
    catch (const std::exception &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
    std::cout << rpn.getTop() << std::endl;
    return 0;
}