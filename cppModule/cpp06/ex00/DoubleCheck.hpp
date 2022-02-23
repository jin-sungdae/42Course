#ifndef DOUBLECHECK_HPP
#define DOUBLECHECK_HPP

#include "Check.hpp"
#include "math.h"

class DoubleCheck : public Check{
public:
    virtual void checkArgs(std::string const args);
    int changeFloat(double num);
    void printDouble(std::string args);
    std::string zeroPlus(double num) const;
};

#endif

