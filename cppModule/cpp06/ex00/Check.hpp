#ifndef CHECK_HPP
#define CHECK_HPP

#include <iostream>
#include <string>

#define NOTYPE 0
#define CHARTYPE 1
#define INTTYPE 2
#define FLOATTYPE 3
#define DOUBLETYPE 4

class Check{
public:
    Check();
    ~Check();
    Check(Check const &c);
    Check&operator=(Check const &c);
    virtual void checkArgs(std::string const args) = 0;
    int analyseInput(std::string input);
    bool getType(std::string input);
    int checkNumValues(std::string input) const;
    int specialCase(std::string const args);

protected:
    int Type;
public:
    class EmptyInput: public std::exception{
        public:
            virtual const char* what() const throw(){
                return "empty input";
            }
    };
    class CannotAnalyse: public std::exception{
        public:
            virtual const char *what() const throw(){
                return "not vaild input";
            }
    };
};

#endif