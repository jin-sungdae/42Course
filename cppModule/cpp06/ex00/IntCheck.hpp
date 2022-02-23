#ifndef INTCHECK_HPP
#define INTCHECK_HPP

#include "Check.hpp"

class IntCheck : public Check{
public:
    virtual void checkArgs(std::string const args);
    void printInt(std::string args);
    int changeInt(double num);
};

#endif