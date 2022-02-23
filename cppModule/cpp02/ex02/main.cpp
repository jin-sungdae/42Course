#include <iostream>
#include "Fixed.hpp"

int main( void ) {
  Fixed a;
  Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

  Fixed c(10.2f);
  Fixed d (8.2f);
  std::cout << "========================" << std::endl;
  std::cout << "six comparison operators" << std::endl;
  std::cout << "========================" << std::endl;
  if (c > d)
    std::cout << c  << " : > " << std::endl;
  if (c >= d)
    std::cout << c << " : >= " << std::endl;
  if (d < c)
    std::cout << d << " : < " << std::endl;
  if (d <= c)
    std::cout << d << " : <= " << std::endl;
  c = 10;
  d = 10;
  if (c == d)
    std::cout << "equal" << std::endl;
  c = 1;
  if (c!= d)
    std::cout << "Not equal" << std::endl;
  
  std::cout << "=========================" << std::endl;
  std::cout << "Four arithmetic operators" << std::endl;
  std::cout << "=========================" << std::endl;
  c = 10;
  d = 2;
  std::cout << "c = " << c << "\n";
  std::cout << "d = " << d << "\n";
  std::cout << "c + d = " << c + d << "\n"; 
  std::cout << "c - d = " << c - d << "\n";
  std::cout << "c * d = " << c * d << "\n";
  std::cout << "c / d = " << c / d << std::endl;

  std::cout << "=============================================================================" << std::endl;
  std::cout << "The pre-increment, post-increment, pre-decrement and post-decrement operators" << std::endl;
  std::cout << "=============================================================================" << std::endl;

  std::cout << "a = " << a << std::endl;
  std::cout << "++a = " << ++a << std::endl;
  std::cout << "a = " << a << std::endl;
  std::cout << "a++ = " << a++ << std::endl;
  std::cout << "a = " << a << std::endl;

  std::cout << "b = " << b << std::endl;

  Fixed const e(10);
  Fixed const f(20);
  std::cout << "=========================" << std::endl;
  std::cout << "    Four min and max     " << std::endl;
  std::cout << "=========================" << std::endl;
  std::cout <<"max = " << Fixed::max( a, b ) << std::endl;
  std::cout <<"min = " << Fixed::min( a, b ) << std::endl; 
  std::cout <<"const max = " << Fixed::max( e, f ) << std::endl;
  std::cout <<"const min = " << Fixed::min( e, f ) << std::endl; 
  return 0;
}
