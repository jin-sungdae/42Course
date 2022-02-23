#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>
class Fixed{
public:
    Fixed();
    ~Fixed();
    Fixed(float const val);
    Fixed(int const val);
    Fixed(const Fixed& f);
    Fixed& operator=(const Fixed& f);
    
    bool operator==(const Fixed& f) const;
    bool operator!=(const Fixed& f) const;
    bool operator>(const Fixed& f) const;
    bool operator<(const Fixed& f) const;
    bool operator>=(const Fixed& f) const;
    bool operator<=(const Fixed& f) const;

    Fixed operator+(const Fixed& f);
    Fixed operator-(const Fixed& f);
    Fixed operator*(const Fixed& f);
    Fixed operator/(const Fixed& f);

    Fixed operator++(int);
    Fixed operator++();
    Fixed operator--(int);
    Fixed operator--();

    static Fixed const &min(Fixed const &a, Fixed const &b);
    static Fixed &min(Fixed &a, Fixed &b);
    static Fixed const &max(Fixed const &a, Fixed const &b);
    static Fixed &max(Fixed &a, Fixed &b);
    int getIntVal() const;
    void setIntVal(const int val);
    float toFloat(void) const;
    int toInt(void) const;

private:
    int intVal;
    const static int bits = 8;
};

std::ostream &operator<<(std::ostream &ost, Fixed const &f);

#endif