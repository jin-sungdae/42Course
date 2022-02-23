#include "IntCheck.hpp"

void IntCheck::checkArgs(std::string const args){
    if (Check::analyseInput(args)){
        printInt(args);
    }
}

void IntCheck::printInt(std::string args){
    char ch = args[0];
    int in = atoi(args.c_str());
    float fl = atof(args.c_str());
    double dou = atof(args.c_str()); 
    if (this->Type == CHARTYPE){
        std::cout << "int :" << static_cast<int>(ch) << std::endl;
    }
    else if (this->Type == INTTYPE){
        std::cout << "int: " << in << std::endl;
    }
    else if (this->Type == FLOATTYPE){
        if (changeInt(fl)){
            std::cout << "int: " << static_cast<int>(fl) << std::endl;
        }
        else{
            std::cout << "int: impossible" << std::endl;
        }
    }
    else if (this->Type == DOUBLETYPE){
        if (changeInt(dou)){
            std::cout << "int: " << static_cast<int>(dou) << std::endl;
        }
        else{
            std::cout << "int: impossible" << std::endl;
        }
    }
}

int IntCheck::changeInt(double num){
    return (num <= std::numeric_limits<int>::max() && num >= std::numeric_limits<int>::min()
    && num != std::numeric_limits<double>::infinity() && num != -std::numeric_limits<double>::infinity()
    && num != std::numeric_limits<double>::quiet_NaN());
}