#include <iostream>

void change_capitial(char **argv)
{
	int i;
	int j;

	i = 1;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (argv[i][j] >= 'a' && argv[i][j] <= 'z')
				argv[i][j] = argv[i][j] - 32;
			j++;
		}
		i++;
	}
	i = 1;
	while (argv[i])
	{
		std :: cout << argv[i++];
	}
	std :: cout << std :: endl;
}

int main(int argc, char **argv)
{
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	else if (argc > 1)
		change_capitial(argv);
	return (0);
}