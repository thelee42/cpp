#include    "Fixed.hpp"
#include    <iostream>

Fixed::Fixed() : _valeur(0) {
    std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed &origin)
{
    std::cout << "Copy constructor called" << std::endl;
    _valeur = origin.getRawBits(); //simple copy constructor
    //*this = origin; : to call copy assignement operator
}

Fixed& Fixed::operator=(const Fixed &origin)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &origin)
        _valeur = origin.getRawBits();
    return *this;
}

int Fixed::getRawBits() const
{
    std::cout << "getRawBits member function called" << std::endl;
    return _valeur;
}


void Fixed::setRawbits(int const raw)
{
    std::cout << "setRawBits member function called" << std::endl;
    _valeur = raw;
}