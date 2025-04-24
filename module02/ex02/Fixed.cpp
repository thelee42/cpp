#include    "Fixed.hpp"
#include    <cmath>

Fixed::Fixed() : _valeur(0) {
    std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const int num) : _valeur(num<<_bit) {
    std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float num)
{
    std::cout << "Float constructor called" << std::endl;
    _valeur = roundf(num * (1 << _bit));
}

Fixed::Fixed(const Fixed &origin)
{
    std::cout << "Copy constructor called" << std::endl;
    //_valeur = origin.getRawBits(); //simple copy constructor
    *this = origin; // to call copy assignement operator
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
    return _valeur;
}


void Fixed::setRawbits(int const raw)
{
    std::cout << "setRawBits member function called" << std::endl;
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

std::ostream& operator<<(std::ostream& out, const Fixed& fixed)
{
    out << fixed.toFloat();
    return out;
}