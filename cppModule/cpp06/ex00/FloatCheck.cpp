#include "FloatCheck.hpp"

void FloatCheck::checkArgs(std::string args){
    if (Check::analyseInput(args)){
        printFloat(args);
    }
}

void FloatCheck::printFloat(std::string args){

    char ch = args[0];
    int in = atoi(args.c_str());
    float fl = atof(args.c_str());
    double dou = atof(args.c_str()); 
    if (this->Type == CHARTYPE){
        std::cout << "float: " << static_cast<float>(ch) << ".0f" << std::endl;
    }
    else if (this->Type == INTTYPE){
        if (static_cast<double>(in) < 1000000)
            std::cout << "float: " << static_cast<float>(in) << ".0f" << std::endl;
        else
            std::cout << "float: " << static_cast<float>(in) << std::endl;
    }
    else if (this->Type == FLOATTYPE){
        std::cout << "float: " << static_cast<float>(fl) << zeroPlus(fl) << "f" << std::endl;
    }
    else if (this->Type ==DOUBLETYPE){
        if (changeFloat(dou)){
            std::cout << "float: " << static_cast<float>(dou) << zeroPlus(dou) << "f" << std::endl;
        }
        else{
            std::cout << "float: impossible" << std::endl;
        }
    }
}

int FloatCheck::changeFloat(double num){
    return  ((num <= std::numeric_limits<float>::max() && num >= -std::numeric_limits<float>::min())
    || num == std::numeric_limits<double>::infinity() || num == -std::numeric_limits<double>::infinity()
    || isnan(num));
}

std::string FloatCheck::zeroPlus(double num) const{
    if (num - static_cast<int>(num) == 0.0){
        return ".0";
    }
    return "";
}