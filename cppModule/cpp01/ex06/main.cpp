#include "karen.hpp"

int main(int ac, char **av)
{
    karen ex = karen();
    std::string level;

    if (ac == 2)
    {
        level = av[1];
        ex.complain(level);
    }
}