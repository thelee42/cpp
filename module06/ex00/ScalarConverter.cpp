#include    "ScalarConverter.hpp"
#include    <cctype>
#include    <cmath>
#include    <iostream>
#include    <cstdlib>
#include    <iomanip>

bool isCharLitteral(const std::string& literal) {
    return (literal.length() == 1 && !std::isdigit(literal[0]));
}

bool isIntLitteral(const std::string& literal) {
    if(literal.empty())
        return false;
    int i = 0;
    if (literal[0] == '+' || literal[0] == '-')
        i = 1;
    for (; i < (int)literal.length(); i++) {
        if (!std::isdigit(literal[i]))
            return false;
    }
    return true;
}

bool isFloatLitteral(const std::string& literal) {
    if (literal.length() < 4)
        return false;
    if (literal[literal.length() - 1] != 'f' && literal[literal.length() - 1] != 'F')
        return false;
    bool point = false;
    int i = 0;
    if (literal[0] == '+' || literal[0] == '-')
        i = 1;
    for (; i < (int)literal.length() - 1; i++) {
        if (literal[i] == '.') {
            if (point)
                return false;
            point = true;
        }
        else if (!std::isdigit(literal[i]))
            return false;
    }
    return point;
}

bool isDoubleLitteral(const std::string& literal) {
    if (literal.length() < 3)
        return false;
    bool point = false;
    int i = 0;
    if (literal[0] == '+' || literal[0] == '-')
        i = 1;
    for (; i < (int)literal.length(); i++) {
        if (literal[i] == '.') {
            if (point)
                return false;
            point = true;
        }
        else if (!std::isdigit(literal[i]))
            return false;
    }
    return point;
}
    
bool isPseudoLitteral(const std::string& literal) {
    return (literal == "-inff" || literal == "+inff" || literal == "nanf"
            || literal == "-inf" || literal == "+inf" || literal == "nan");
}

void printChar(char var) {
    std::cout << "char: ";
    if (var < 0 || var > 127)
        std::cout << "impossible" << std::endl;
    else if (!std::isprint(var))
        std::cout << "Non displayable" << std::endl;
    else
        std::cout << "'" << var << "'" << std::endl;
}

void printInt(int var) {
    std::cout << "int: ";
    if (var < std::numeric_limits<int>::min() || var > std::numeric_limits<int>::max())
        std::cout << "impossible" << std::endl;
    else
        std::cout << var << std::endl;
}

void printFloat(float var) {
    std::cout << "float: ";
    if(std::isnan(var))
        std::cout << "nanf" << std::endl;
    else if(std::isinf(var))
        std::cout << (var < 0 ? "-inff" : "+inff") << std::endl;
    else
        std::cout << std::fixed << std::setprecision(1) << var << "f" << std::endl;
}

void printDouble(double var) {
    std::cout << "double: ";
    if(std::isnan(var))
        std::cout << "nan" << std::endl;
    else if(std::isinf(var))
        std::cout << (var < 0 ? "-inf" : "+inf") << std::endl;
    else
        std::cout << std::fixed << std::setprecision(1) << var << std::endl;
}


void ScalarConverter::convert(const std::string& literal) {
    if (isPseudoLitteral(literal)) {
        double d = 0.0;
        if (literal == "nan" || literal == "nanf")
            d = std::numeric_limits<double>::quiet_NaN();
        else if (literal == "+inf" || literal == "+inff")
            d = std::numeric_limits<double>::infinity();
        else if (literal == "-inf" || literal == "-inff")
            d = -std::numeric_limits<double>::infinity();
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        printFloat(static_cast<float>(d));
        printDouble(d);
    }
    else if (isCharLitteral(literal)) {
        char c = literal[0];
        printChar(c);
        printInt(static_cast<int>(c));
        printFloat(static_cast<float>(c));
        printDouble(static_cast<double>(c));
    }
    else if (isIntLitteral(literal)) {
        int i = std::atoi(literal.c_str());
        printChar(static_cast<char>(i));
        printInt(i);
        printFloat(static_cast<float>(i));
        printDouble(static_cast<double>(i));
    }
    else if (isFloatLitteral(literal)) {
        std::string floatstr = literal.substr(0, literal.length() - 1);
        double d = std::strtod(floatstr.c_str(), NULL);
        printChar(static_cast<char>(d));
        printInt(static_cast<int>(d));
        printFloat(static_cast<float>(d));
        printDouble(d);
    }
    else if (isDoubleLitteral(literal)) {
        double d = std::strtod(literal.c_str(), NULL);
        printChar(static_cast<char>(d));
        printInt(static_cast<int>(d));
        printFloat(static_cast<float>(d));
        printDouble(d);
    }
    else
        std::cout << "Conversion Impossible" << std::endl;    
}
