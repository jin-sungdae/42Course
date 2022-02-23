#include "Fixed.hpp"

Fixed::Fixed() : intVal(0) {}
Fixed::~Fixed(){}
Fixed::Fixed(int const val) : intVal(val << Fixed::bits){}
Fixed::Fixed(float const val) : intVal(roundf(val * (1 << Fixed::bits))){}
Fixed::Fixed(const Fixed& f) : intVal(f.getIntVal()){}
Fixed& Fixed::operator=(const Fixed& f) {this->intVal = f.getIntVal();return (*this);}
bool Fixed::operator==(const Fixed& f) const {return (this->getIntVal() == f.getIntVal());}
bool Fixed::operator!=(const Fixed& f) const {return (this->getIntVal()!= f.getIntVal());}
bool Fixed::operator>(const Fixed& f) const {return (this->getIntVal() > f.getIntVal());}
bool Fixed::operator<(const Fixed& f) const {return (this->getIntVal() < f.getIntVal());}
bool Fixed::operator>=(const Fixed& f) const {return (this->getIntVal() >= f.getIntVal());}
bool Fixed::operator<=(const Fixed& f) const {return (this->getIntVal() <= f.getIntVal());}

Fixed Fixed::operator+(const Fixed& f){Fixed tmp(*this); tmp.setIntVal(tmp.getIntVal() + f.getIntVal()); return (tmp);}
Fixed Fixed::operator-(const Fixed& f){Fixed tmp(*this); tmp.setIntVal(tmp.getIntVal() - f.getIntVal()); return (tmp);}
Fixed Fixed::operator*(const Fixed& f)
{
    Fixed tmp(*this);
    long tmp1, tmp2;
    tmp1 = ((long)this->getIntVal());
    tmp2 = ((long)f.getIntVal());
    tmp.setIntVal((tmp1 * tmp2) / (1 << Fixed::bits));
    return (tmp);
}
Fixed Fixed::operator/(const Fixed& f)
{
    Fixed tmp(*this);
    long tmp1, tmp2;
    tmp1 = ((long)this->getIntVal());
    tmp2 = ((long)f.getIntVal());
    tmp.setIntVal((tmp1 * (1 << Fixed::bits)) / tmp2);
    return (tmp);
}

Fixed Fixed::operator++(int){Fixed tmp(*this); operator++(); return (tmp);}
Fixed Fixed::operator++(){this->intVal++; return (*this);}
Fixed Fixed::operator--(int){Fixed tmp(*this); operator--(); return (tmp);}
Fixed Fixed::operator--(){this->intVal--; return (*this);}

Fixed const &Fixed::min(Fixed const &a, Fixed const &b){if (a > b) return (b); return (a);}
Fixed &Fixed::min(Fixed &a, Fixed &b){if (a > b) return (b); return (a);}
Fixed const &Fixed::max(Fixed const &a, Fixed const &b){if (a > b) return (a); return (b);}
Fixed &Fixed::max(Fixed &a, Fixed &b){if (a > b) return (a); return (b);}

int Fixed::getIntVal() const{return intVal;}
void Fixed::setIntVal(const int val){intVal = val;}
float Fixed::toFloat(void) const{return ((float)this->intVal / (float)(1 << Fixed::bits));}
int Fixed::toInt(void) const{return (this->intVal >> Fixed::bits);}

std::ostream &operator<<(std::ostream &ost, Fixed const &f){ost << f.toFloat(); return (ost);}