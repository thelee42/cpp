#include    "BitcoinExchange.hpp"
#include    <fstream>
#include    <sstream>
#include    <iostream>



BitcoinExchange::BitcoinExchange() : database() {}

BitcoinExchange::BitcoinExchange(const char* input) 
{
    int len = std::strlen(input);
    if (len < 4 || std::strcmp(input + len - 4, ".csv") != 0)
        throw std::runtime_error("Data file must be a .csv file");
    std::ifstream file(input);
    if (!file.is_open())
        throw std::runtime_error("Cannot open data file");
    std::string line;
    std::getline(file, line); // skip header
    while (std::getline(file, line))
    {
        char delim = ',';
        if (line.find('|') != std::string::npos)
            delim = '|';
        std::stringstream ss(line);
        std::string date, value;
        std::getline(ss, date, delim);
        while (!date.empty() && std::isspace(date[date.size()-1]))
            date.erase(date.size()-1);
        std::getline(ss, value);
        double price;
        std::stringstream valuess(value);
        if(!(valuess >> price) || !valuess.eof())
            throw std::runtime_error("Invalid price");
        database[date] = price;
    }
}


BitcoinExchange::~BitcoinExchange() {}


BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) : database(other.database) {}


BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other)
{
    if (this != &other) {
        database = other.database;
    }
    return *this;
}


double BitcoinExchange::getValue(const std::string& date) const 
{
    std::map<std::string, double>::const_iterator it = database.lower_bound(date);
    if (it != database.end() && it->first == date)
        return it->second;
    if (it == database.begin())
        throw std::runtime_error("No data available for this date");
    --it;
    return it->second;
}

bool isValidDate(const std::string& date) {
    if (date.length() != 10 || date[4] != '-' || date[7] != '-')
        return false;
    for (int i = 0; i < 10; i++)
    {
        if (i == 4 || i == 7)
            continue;
        if (!std::isdigit(date[i]))
            return false;
    }
    int month = std::atoi(date.substr(5, 2).c_str());
    int day = std::atoi(date.substr(8, 2).c_str());
    if (month < 1 || month > 12 || day < 1 || day > 31)
        return false;
    return true;
}

void BitcoinExchange::calculate(const char* inputFile) const {
    std::ifstream file(inputFile);
    if (!file.is_open())
        throw std::runtime_error("Cannot open Input file");
    std::string line;
    std::getline(file, line);
    while(getline(file, line))
    {
        if (line.find('|') == std::string::npos)
        {
            std::cerr << "Error: bad input => " << line << std::endl;
            continue;
        }
        std::stringstream ss(line);
        std::string date, value;
        std::getline(ss, date, '|');
        while(!date.empty() && std::isspace(date[date.length()-1]))
            date.erase(date.length()-1);
        if (!isValidDate(date))
        {
            std::cerr << "Error: invalid date => " << date << std::endl;
            continue;
        }
        std::getline(ss, value);
        double amount;
        std::stringstream valuess(value);

        if(!(valuess >> amount) || !valuess.eof())
        {
            std::cerr << "Error: invalid input value => " << value << std::endl;
            continue;
        }
        if (amount < 0)
        {
            std::cerr << "Error: not a positive number => " << value << std::endl;
            continue;
        }
        if (amount > 1000)
        {
            std::cerr << "Error: number out of range => " << value << std::endl;
            continue;
        }
        double exchange = getValue(date);
        std::cout << date << " => " << amount << " = " << amount * exchange << std::endl;
    }
    
}