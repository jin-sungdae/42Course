#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include "Base.hpp"

#include <iostream>

Base * generate(void){
    if (rand() % 3 == 0){
        return new A();
    }
    else if (rand() % 3 == 1){
        return new B();
    }
    return new C();
}

void identify(Base *p){
    A *a;
    B *b;
    C *c;

    if ((a = dynamic_cast<A *>(p)))
        std::cout << "A" << std::endl;
    else if ((b = dynamic_cast<B *>(p)))
        std::cout << "B" << std::endl;
    else if ((c = dynamic_cast<C *>(p)))
        std::cout << "C" << std::endl;
}

void identify(Base &p){

    try{
        A &a = dynamic_cast<A &>(p);
        (void)a;
        std::cout << "A" << std::endl;
    }catch (std::exception &e){
        (void)e;
    }
    try{
        B &b = dynamic_cast<B &>(p);
        (void)b;
        std::cout << "B" << std::endl;
    }catch (std::exception &e){
        (void)e;
    }
    try{
        C &c = dynamic_cast<C &>(p);
        (void)c;
        std::cout << "C" << std::endl;
    }catch (std::exception &e){
        (void)e;
    }
}

int main(){

    Base *base;

    base = generate();
    identify(base);
    delete base;

    base = generate();
    identify(base);
    delete base; 
    
    base = generate();
    identify(base);
    delete base; 
    
    base = generate();
    identify(base);
    delete base; 
    
    base = generate();
    identify(base);
    delete base; 
    
    base = generate();
    identify(base);
    delete base; 
    
    base = generate();
    identify(base);
    delete base; 
    
    base = generate();
    identify(base);
    delete base;

    std::cout << "=============reference===============" << "\n" << std::endl;

    base = generate();
    identify(*base);
    delete base;
    base = generate();
    identify(*base);
    delete base;
    base = generate();
    identify(*base);
    delete base;
    base = generate();
    identify(*base);
    delete base;
    base = generate();
    identify(*base);
    delete base;
    base = generate();
    identify(*base);
    delete base;
    base = generate();
    identify(*base);
    delete base;
    base = generate();
    identify(*base);
    delete base;
    base = generate();
    identify(*base);
    delete base;
    base = generate();
    identify(*base);
    delete base;
    base = generate();
    identify(*base);
    delete base;
}