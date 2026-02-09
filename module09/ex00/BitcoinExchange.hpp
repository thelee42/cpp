#ifndef BitcoinExchange_HPP
# define BitcoinExchange_HPP

#include    <map>
#include    <string>
#include    <stdexcept>
#include    <iostream>

class BitcoinExchange
{
    private:
        std::map<std::string, double> database;
    public:
        BitcoinExchange();
        BitcoinExchange(const char* input);
        ~BitcoinExchange();
        BitcoinExchange(const BitcoinExchange& other);
        BitcoinExchange& operator=(const BitcoinExchange& other);
        double getValue(const std::string& date) const;
        void calculate(const char* inputFile) const;
};


#endif


// lower_bound : 이상(포함)
// upper_bound : 초과(미포함)