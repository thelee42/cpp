#ifndef FIXED_HPP
# define FIXED_HPP

#include    <iostream>

#define BIT 8;

class Fixed
{
    private:
    int _valeur;
    const static int _bit = BIT;

    public:
    Fixed();
    ~Fixed();
    Fixed(const int num);
    Fixed(const float num);

    Fixed(const Fixed &origin);
    Fixed& operator=(const Fixed &origin);
    int getRawBits() const;
    void setRawbits(int const raw);
    float toFloat() const;
    int toInt() const;

    bool operator>(const Fixed &origin) const;
    bool operator<(const Fixed &origin) const;
    bool operator>=(const Fixed &origin) const;
    bool operator<=(const Fixed &origin) const;
    bool operator==(const Fixed &origin) const;
    bool operator!=(const Fixed &origin) const;

    Fixed operator+(const Fixed &origin);
    Fixed operator-(const Fixed &origin);
    Fixed operator*(const Fixed &origin);
    Fixed operator/(const Fixed &origin);

    Fixed& operator++();
    Fixed operator++(int);
    Fixed& operator--();
    Fixed operator--(int);
    
    static Fixed& min(Fixed& a, Fixed& b);
    static const Fixed& min(const Fixed& a, const Fixed& b);
    static Fixed& max(Fixed& a, Fixed& b);
    static const Fixed& max(const Fixed& a, const Fixed& b);
};

std::ostream& operator<<(std::ostream& out, const Fixed& fixed);

#endif