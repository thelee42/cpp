#ifndef FIXED_HPP
# define FIXED_HPP

class Fixed
{
    private:
    int _valeur;
    const static int _bit = 8;

    public:
    Fixed();
    ~Fixed();
    Fixed(const Fixed &origin);
    Fixed& operator=(const Fixed &origin);
    int getRawBits() const;
    void setRawbits(int const raw);
};

#endif