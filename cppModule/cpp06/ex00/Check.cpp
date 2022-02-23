#include "Check.hpp"

Check::Check(){
    Type = 0;
}

Check::~Check(){
}

Check::Check(Check const &c): Type(c.Type){
    *this = c;
}

Check & Check::operator=(Check const & c){
    this->Type = c.Type;
    return *this;
}

int Check::checkNumValues(std::string input) const{
    int i = 0;
    int cnt = 0;

    if (input[0] == '-' && input[1])
        i++;
    if (input[i] == '.' && (input[i + 1] == 'f' || input[i + 1] == 0))
        return 0;
    while (input[i] == '.' || isdigit(input[i])){
        if (input[i] == '.')
            cnt++;
        if (cnt > 1)
            return NOTYPE;
        i++;
    }
    if (!input[i]){
        if (cnt == 1){
            return DOUBLETYPE;
        }
        return INTTYPE;
    }
    else if (input[i] == 'f' && !input[i + 1] && cnt == 1){
        return FLOATTYPE;
    }
    return NOTYPE;
}

bool Check::getType(std::string input){
    this->Type = Check::specialCase(input);
    if (this->Type != NOTYPE)
        return true;
    if((input[0] >= '0' && input[0] <= '9') || input[0] == '-' || input[0] == '.'){
        this->Type = Check::checkNumValues(input);
        if (this->Type != NOTYPE)
            return true;
    }
    if (input[1])
        return false;
    this->Type = CHARTYPE;
    return true;
}

int Check::analyseInput(std::string input){
    if (input[0] == 0){
        throw Check::EmptyInput();
    }
    if (!this->getType(input)){
        throw Check::CannotAnalyse();
    }
    return 1;
}

int Check::specialCase(std::string const args){
    const std::string specialDouble[] = {
        "inf", "+inf", "-inf", "nan"
    };
    const std::string specialFloat[] = {
        "inff", "+inff", "-inff", "nanf"
    };
    for (int i = 0; i < 4; i++){
        if (specialDouble[i] == args){
            return DOUBLETYPE;
        }
        else if (specialFloat[i] == args){
            return FLOATTYPE;
        }
    }
    return NOTYPE;
 }