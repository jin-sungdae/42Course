#ifndef FLOATCHECK_HPP
#define FLOATCHECK_HPP

#include "Check.hpp"
#include "math.h"

class FloatCheck : public Check{
public:
    virtual void checkArgs(std::string const args);
    int analyseInput(std::string input);
    void printFloat(std::string args);
    int changeFloat(double num);
    std::string zeroPlus(double num) const;
};

#endif