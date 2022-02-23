#ifndef KAREN
#define KAREN
#include <iostream>

class karen;

typedef struct s_functionList{
    std::string level;
    void (karen::*function)(void);
}             t_functionList;

class karen{
private:
    void debug(void);
    void info(void);
    void warning(void);
    void error(void);
    t_functionList list[4];
public:
    void complain(std::string level);
    ~karen();
    karen();
};

#endif 