#ifndef B_HPP
#define B_HPP

#include "Base.hpp"

class B : public Base{
public:
    B();
    ~B();
    B(B const & b);
    B&operator=(B const & b);
};

#endif