#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>

class WrongAnimal{
protected:
    std::string type;
public:
    WrongAnimal();
    ~WrongAnimal();
    std::string getType() const;
    void setType(std::string const type);
    virtual void makeSound() const;

};

#endif