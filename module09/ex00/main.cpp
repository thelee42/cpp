#include    "BitcoinExchange.hpp"

int main(int ac, char** av)
{
    if (ac != 2)
    {
        std::cerr << "Error: need one input file" << std::endl;
        return 1;
    }
    try
    {
        BitcoinExchange btc("data.csv");
        btc.calculate(av[1]);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        return 1;
    }
    return 0;
}