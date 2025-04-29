#include    "Fixed.hpp"

Fixed Fixed::operator+(const Fixed &origin)
{
    Fixed res;
    res.setRawbits(this->_valeur + origin.getRawBits());
    return res;
}
Fixed Fixed::operator-(const Fixed &origin)
{
    Fixed res;
    res.setRawbits(this->_valeur - origin.getRawBits());
    return res;
}
Fixed Fixed::operator*(const Fixed &origin)
{
    Fixed res;
    res.setRawbits((this->_valeur * origin.getRawBits()) >> 8);
    return res;
}
Fixed Fixed::operator/(const Fixed &origin)
{
    if(origin.getRawBits() == 0)
    {
        std::cerr << "Error: Division by zero!" << std::endl;
        return *this;
    }
    Fixed res;
    res.setRawbits((this->_valeur << 8) / origin.getRawBits());
    return res;
}

Fixed& Fixed::operator++()
{
    this->_valeur++;
    return *this;
}
Fixed Fixed::operator++(int)
{
    Fixed temp(*this);
    this->_valeur++;
    return temp;
}

Fixed& Fixed::operator--()
{
    this->_valeur--;
    return *this;
}

Fixed Fixed::operator--(int)
{
    Fixed temp(*this);
    this->_valeur--;
    return temp;
}