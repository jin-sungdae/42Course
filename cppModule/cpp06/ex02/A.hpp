#ifndef A_HPP
#define A_HPP

#include "Base.hpp"
#include <iostream>
class A : public Base{
public:
    A();
    ~A();
    A(A const & a);
    A & operator=(A const & a);
};


#endif