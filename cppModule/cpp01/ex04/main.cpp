#include <iostream>

class Replace{
private:

public:

};

int main(int ac, char **av)
{
	std::string fileName;
	std::string s1;
	std::string s2;
	if (ac == 4)
	{
		fileName = av[1];
		s1 = av[2];
		s2 = av[3];

	}
	else
		return (0);
	return (1);
}