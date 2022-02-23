#ifndef ICE_HPP
#define ICE_HPP

#include "AMateria.hpp"

class Ice : public AMateria{
public:
    Ice();
    ~Ice();
    Ice(Ice const &i);
    Ice &operator=(Ice const &i);
    virtual AMateria *clone() const;
    virtual void use(ICharacter& target);
};

#endif