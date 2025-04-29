#include    "Fixed.hpp"
#include    <cmath>

Fixed::Fixed() : _valeur(0) {}

Fixed::~Fixed() {}

Fixed::Fixed(const int num) : _valeur(num<<_bit) {}

Fixed::Fixed(const float num)
{
        _valeur = roundf(num * (1 << _bit));
}

Fixed::Fixed(const Fixed &origin)
{
    //_valeur = origin.getRawBits(); //simple copy constructor
    *this = origin; // to call copy assignement operator
}

Fixed& Fixed::operator=(const Fixed &origin)
{
    if (this != &origin)
        _valeur = origin.getRawBits();
    return *this;
}

int Fixed::getRawBits() const
{
    return _valeur;
}

void Fixed::setRawbits(int const raw)
{
    _valeur = raw;
}

float Fixed::toFloat() const
{
    return (static_cast<float>(_valeur) / (1 << _bit));
}

int Fixed::toInt() const
{
    return (_valeur >> _bit);
}

