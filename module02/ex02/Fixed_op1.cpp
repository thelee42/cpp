#include    "Fixed.hpp"

bool Fixed::operator>(const Fixed &origin) const
{
    return(_valeur > origin.getRawBits());
}

bool Fixed::operator<(const Fixed &origin) const
{
    return(_valeur < origin.getRawBits());
}

bool Fixed::operator>=(const Fixed &origin) const
{
    return(_valeur >= origin.getRawBits());
}

bool Fixed::operator<=(const Fixed &origin) const
{
    return(_valeur <= origin.getRawBits());
}

bool Fixed::operator==(const Fixed &origin) const
{
    return(_valeur == origin.getRawBits());
}

bool Fixed::operator!=(const Fixed &origin) const
{
    return(_valeur != origin.getRawBits());
}