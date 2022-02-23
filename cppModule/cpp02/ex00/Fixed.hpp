#ifndef FIXED_HPP
#define FIXED_HPP
#include <iostream>

class Fixed{
public:
    Fixed();
    ~Fixed();
    Fixed(const Fixed& f);
    Fixed& operator=(const Fixed& f);
    int getRawBits(void) const;
    void setRawBits(int const raw);
private:
    int RawBits;
    static const int bits = 8;
};
#endif