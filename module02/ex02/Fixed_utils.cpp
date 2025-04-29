#include    "Fixed.hpp"

std::ostream& operator<<(std::ostream& out, const Fixed& fixed)
{
    out << fixed.toFloat();
    return out;
}

Fixed& Fixed::min(Fixed& a, Fixed& b)
{
    return (a < b) ? a : b;
}
const Fixed& Fixed::min(const Fixed& a, const Fixed& b)
{
    return (a < b) ? a : b;
}
Fixed& Fixed::max(Fixed& a, Fixed& b)
{
    return (a > b) ? a : b;
}
const Fixed& Fixed::max(const Fixed& a, const Fixed& b)
{
    return (a > b) ? a : b;
}

//선언때는 static 붙이고 구현때는 안붙임