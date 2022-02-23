#include "Fixed.hpp"

Fixed::Fixed()
{
    this->RawBits = 0;
    std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(int const val)
{
    std::cout << "Int constructor called" << std::endl;
    RawBits = (val << Fixed::bits);
}

Fixed::Fixed(float const val)
{
    std::cout << "Float constructor called" << std::endl;
    RawBits = roundf(val * (1 << Fixed::bits));
}

Fixed::Fixed(const Fixed& f)
{
    this->RawBits = f.getRawBits();
    std::cout << "Copy constructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed& f)
{
    this->RawBits = f.getRawBits();
    std::cout << "Assignation operator called" << std::endl;
    return (*this);
}

void Fixed::setRawBits(const int raw)
{
    this->RawBits = raw;
    std::cout << "setRawBits member function called" << std::endl;
}

int Fixed::getRawBits(void) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return this->RawBits;
}

std::ostream &operator<<(std::ostream &ost, const Fixed& f)
{
    ost << f.toFloat();
    return (ost);
}

float Fixed::toFloat(void) const
{
    return ((float)this->RawBits / (float)(1 << Fixed::bits));
}

int Fixed::toInt(void) const
{
    return (this->RawBits >> Fixed::bits);
}