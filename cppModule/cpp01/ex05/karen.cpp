#include "karen.hpp"

void karen::debug(void)
{
    std::cout << "[" << "DEBUG" << "]" << std::endl;
    std::cout << "I love to get extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I just love it!" << std::endl;
}
void karen::info(void)
{
    std::cout << "[" << "INFO" << "]" << std::endl;
    std::cout << "I cannot believe adding extra bacon cost more money. You don’t put enough! If you did I would not have to ask for it!" << std::endl;
}
void karen::warning(void)
{   
    std::cout << "[" << "WARNING" << "]" << std::endl;
    std::cout <<  "I think I deserve to have some extra bacon for free. I’ve been coming here for years and you just started working here last month." << std::endl;
}
void karen::error(void)
{   
    std::cout << "[" << "ERROR" << "]" << std::endl;
    std::cout << "This is unacceptable, I want to speak to the manager now." << std::endl;
}

karen::karen()
{
    list[0].level = "DEBUG";
    list[0].function = &karen::debug;
    list[1].level = "INFO";
    list[1].function = &karen::info;
    list[2].level = "WARNING";
    list[2].function = &karen::warning;
    list[3].level = "ERROR";
    list[3].function = &karen::error;
}
karen::~karen(){}

void karen::complain(std::string level)
{

    for (int i = 0; i < 4; i++)
    {
        if (list[i].level == level)
			return (this->*list[i].function)();
    }
} 