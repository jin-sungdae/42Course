#ifndef CHARCHECK_HPP
#define CHARCHECK_HPP

#include "Check.hpp"
class CharCheck : public Check{
public:
    virtual void checkArgs(std::string const args);
    void printChar(std::string args);
    int  changeChar(double num);
private:
};

#endif
