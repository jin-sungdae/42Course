#include <iostream>

int main()
{
    std::string str = "HI THIS IS BRAIN";
    std::string *strPTR = &str;
    std::string &strREF = str;

    std::cout << "===================================" << std::endl;
	std::cout << " display the address of the string " << std::endl;
	std::cout << "===================================" << std::endl;
    std::cout << "str 주소값 = " << &str << std::endl;
    std::cout << "strPTR 주소값 = " << strPTR << std::endl;
    std::cout << "strREF 주소값 = " << &strREF << std::endl;

    std::cout << "====================================" << std::endl;
	std::cout << "         display the string         " << std::endl;
	std::cout << "====================================" << std::endl;
    std::cout << "str = " << str << std::endl;
    std::cout << "strPTR = " << *strPTR << std::endl;
    std::cout << "strREF = " << strREF << std::endl;
}