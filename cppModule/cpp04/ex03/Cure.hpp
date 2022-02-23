#ifndef CURE_HPP
#define CURE_HPP

#include "AMateria.hpp"

class Cure : public AMateria{
public:
    Cure();
    Cure(Cure const &c);
    ~Cure();
    Cure & operator=(Cure const &c);
    virtual AMateria *clone() const;
    virtual void use(ICharacter &target);
};

#endif