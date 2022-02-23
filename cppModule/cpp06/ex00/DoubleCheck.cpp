#include "DoubleCheck.hpp"

void DoubleCheck::checkArgs(std::string args){

    if(Check::analyseInput(args)){
        printDouble(args);
    }
}

void DoubleCheck::printDouble(std::string args){
    char ch = args[0];
    int in = atoi(args.c_str());
    float fl = atof(args.c_str());
    double dou = atof(args.c_str()); 
    if (this->Type == CHARTYPE){
        std::cout << "double: " << static_cast<double>(ch) << ".0" << std::endl;
    }
    else if (this->Type == INTTYPE){
        if (static_cast<double>(in) < 1000000)
            std::cout << "double: " << static_cast<double>(in) << ".0" << std::endl;
        else
            std::cout << "double: " << static_cast<double>(in) << std::endl;
    }
    else if (this->Type == FLOATTYPE){
        std::cout << "double: " << static_cast<double>(fl) << zeroPlus(fl)  << std::endl;
    }
    else if (this->Type == DOUBLETYPE){
        if (changeFloat(dou)){
            std::cout << "double: " << static_cast<double>(dou) << zeroPlus(dou)  << std::endl;
        }
        else{
            std::cout << "double: impossible" << std::endl;
        }
    }
}


int DoubleCheck::changeFloat(double num){
    return  ((num <= std::numeric_limits<float>::max() && num >= -std::numeric_limits<float>::min())
        || num == std::numeric_limits<double>::infinity() || num == -std::numeric_limits<double>::infinity()
        || isnan(num));
}

std::string DoubleCheck::zeroPlus(double num) const{
    if (num - static_cast<int>(num) == 0.0){
        return ".0";
    }
    return "";
}