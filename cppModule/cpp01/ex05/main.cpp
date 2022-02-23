#include "karen.hpp"

int main()
{
    karen ex = karen();

    ex.complain("DEBUG");
    ex.complain("info");
    ex.complain("INFO");
    ex.complain("debug");
    ex.complain("warning");
    ex.complain("WARNING");
    ex.complain("error");
    ex.complain("ERROR");

}