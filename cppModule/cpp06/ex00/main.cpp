#include "CharCheck.hpp"
#include "DoubleCheck.hpp"
#include "FloatCheck.hpp"
#include "IntCheck.hpp"

int main(int ac, char **av){
    try{
        if (ac == 1)
            throw Check::EmptyInput();
        if (ac == 2){
            CharCheck *cha = new CharCheck();
            IntCheck *in = new IntCheck();
            FloatCheck *fl = new FloatCheck();
            DoubleCheck *dob = new DoubleCheck();
            cha->checkArgs(av[1]);
            in->checkArgs(av[1]);
            fl->checkArgs(av[1]);
            dob->checkArgs(av[1]);
        }
    }catch (std::exception &e){
        std::cout << e.what() << std::endl;
    }
}