#include "CharCheck.hpp"

void CharCheck::checkArgs(std::string args){
    
    if (Check::analyseInput(args)){
        printChar(args);
    }
}

void CharCheck::printChar(std::string args){
    char ch = args[0];
    int in = atoi(args.c_str());
    float fl = atof(args.c_str());
    double dou = atof(args.c_str()); 
    if (this->Type == INTTYPE){
        if (changeChar(in)){
            std::cout << "char: " << static_cast<char>(in) << std::endl;
        }
    }
    else if (this->Type == FLOATTYPE){
        if (changeChar(fl)){
            std::cout << "char: " << "\'" << static_cast<char>(fl) << "\'" << std::endl;
        }
    }
    else if (this->Type == DOUBLETYPE){
        if (changeChar(dou)){
            std::cout << "char: " << "\'" << static_cast<char>(dou) << "\'" << std::endl;
        }
    }
    else{
        std::cout << "char: " << ch << std::endl;
    }
}

int CharCheck::changeChar(double num){
    if (num - static_cast<int>(num) != 0 || num > 127 || num <0){
        std::cout << "char: impossible" << std::endl;
    }
    else if (num <= 31 || num == 127){
        std::cout << "char: Non displayable" << std::endl;
    }
    else{
        return 1;
    }
    return 0;
    
}