#ifndef FIXED_HPP
# define FIXED_HPP

#define BIT 8;

class Fixed
{
    private:
    int _valeur;
    const static int _bit = BIT;

    public:
    Fixed();
    ~Fixed();
    Fixed(const Fixed &origin);
    Fixed& operator=(const Fixed &origin);
    int getRawBits() const;
    void setRawbits(int const raw);
};

#endif