#ifndef FIXED_HPP
# define FIXED_HPP

#include    <iostream>

class Fixed
{
    private:
    int _valeur;
    const static int _bit = 8;

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
    bool operator>(const Fixed &origin);
    bool operator<(const Fixed &origin);
    bool operator>=(const Fixed &origin);
    bool operator<=(const Fixed &origin);
    bool operator==(const Fixed &origin);
    bool operator!=(const Fixed &origin);
    Fixed& operator+(const Fixed &origin);
    Fixed& operator-(const Fixed &origin);
    Fixed& operator*(const Fixed &origin);
    Fixed& operator/(const Fixed &origin);
};

std::ostream& operator<<(std::ostream& out, const Fixed& fixed);

#endif