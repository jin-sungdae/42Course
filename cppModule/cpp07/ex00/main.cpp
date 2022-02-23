#include "whatever.hpp"
#include <iostream>

int main(){
    char a, b;
    short c, d;
    int e, f;
    float g, h;


    a = 'a';
    b = 'b';
    c = 1;
    d = 2;
    e = 1000;
    f = 2000;
    g = 19.3;
    h = 27.3;
    std::cout << "a = " << a << ", b = " << b << std::endl;
    ::swap (a, b);
    std::cout << "a = " << a << ", b = " << b << std::endl;
    std::cout << "min(a, b) = " << ::min(a,b) << std::endl;
    std::cout << "max(a, b) = " << ::max(a,b) << std::endl;
    std::cout << "\n";

    std::cout << "c = " << c << ", d = " << d << std::endl;
    ::swap (c, d);
    std::cout << "c = " << c << ", d = " << d << std::endl;
    std::cout << "min(c, d) = " << ::min(c,d) << std::endl;
    std::cout << "max(c, d) = " << ::max(c,d) << std::endl;
    std::cout << "\n";

    std::cout << "e = " << e << ", f = " << f << std::endl;
    ::swap (e, f);
    std::cout << "e = " << e << ", f = " << f << std::endl;
    std::cout << "min(e, f) = " << ::min(e,f) << std::endl;
    std::cout << "max(e, f) = " << ::max(e,f) << std::endl;
    std::cout << "\n";

    std::cout << "g = " << g << ", h = " << h << std::endl;
    ::swap (g, h);
    std::cout << "g = " << g << ", h = " << h << std::endl;
    std::cout << "min(g, h) = " << ::min(g,h) << std::endl;
    std::cout << "max(g, h) = " << ::max(g,h) << std::endl;
    std::cout << "\n";
  
    std::string str1 = "chaine1";
    std::string str2 = "chaine2";
    std::cout << "str1 = " << str1 << ", str2 = " << str2 << std::endl;
    ::swap(str1, str2);
    std::cout << "str1 = " << str1 << ", str2 = " << str2 << std::endl;
    std::cout << "min(a, b) = " << ::min(str1, str2) << std::endl;
    std::cout << "max(a, b) = " << ::max(str1, str2) << std::endl;
}
