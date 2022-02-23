#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed{
private:
    const static int bits = 8;
    int RawBits;
public:
    Fixed();
    Fixed(float const val);
    Fixed(int const val);
    ~Fixed();
    Fixed(const Fixed& f);
    Fixed& operator=(const Fixed& f);
    int getRawBits() const;
    void setRawBits(const int raw);
    float toFloat(void) const;
    int toInt(void) const;

};
std::ostream &operator<<(std::ostream &ost, const Fixed& f);
#endif