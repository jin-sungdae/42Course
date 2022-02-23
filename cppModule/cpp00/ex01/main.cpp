#include "array.hpp"

int main()
{
	std :: string oper;
	int i;
	Array ar;

	i = 0;
	while (1)
	{
		std::cout << RED << "=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=\n";
		std::cout << CYN  "press push cmd : SEARCH | ADD | EXIT" << NC << std::endl;
		std :: cin >> oper;
		if (oper == "SEARCH")
			ar.searchBook();
		else if (oper == "ADD")
			ar.addBook();
		else if (oper == "EXIT")
			break;
	}
	return (0);
}