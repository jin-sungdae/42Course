#include "minishell.h"

void	ef_init(t_ef *ef)
{
	ef->row = 0;
	ef->i = 0;
}

void	plus_row(char *str, t_ef *ef, char c)
{
	ef->row++;
	while (str[ef->i] && str[ef->i] == c)
		ef->i++;
}

void	plus_i(char *str, t_ef *ef)
{
	while (str[ef->i] && (str[ef->i] != '\''\
		|| str[ef->i] != '\\' || str[ef->i] != '\"'))
		ef->i++;
}
