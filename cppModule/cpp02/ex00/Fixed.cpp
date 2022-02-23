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

Fixed::Fixed(const Fixed& f)
{
    std::cout << "Copy constructor called" << std::endl;
    this->RawBits = f.getRawBits();
}

Fixed& Fixed::operator=(const Fixed& f)
{
    this->RawBits = f.getRawBits();
    std::cout << "Assignation operator called" << std::endl;
    return (*this);
}

int Fixed::getRawBits(void) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return RawBits;
}

void Fixed::setRawBits(int const raw)
{
    std::cout << "setRawBits member function called" << std::endl;
    RawBits = raw;
}