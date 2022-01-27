#include "libft.h"

int	check_row(char *str, char c)
{
	t_ef	ef;

	ef_init(&ef);
	while (str[ef.i] && str[ef.i] == c)
		ef.i++;
	while (str[ef.i])
	{
		if (str[ef.i] == c)
			plus_row(str, &ef, c);
		else if (str[ef.i] == '\'' || \
		str[ef.i] == '\\' || str[ef.i] == '\"')
			plus_i(str, &ef);
		else
			ef.i++;
	}
	if (str[ef.i - 1] != c)
		ef.row++;
	return (ef.row);
}

int	find_new_column(const char *str)
{
	int	i;
	int	check;

	check = 0;
	i = 0;
	while (str[i])
	{
		if (check == 0 && (str[i] == '\''))
			check = 1;
		else if (check == 1 && (str[i] == '\''))
			break ;
		i++;
	}
	return (i - 1);
}

char	**malloc_free(char **new_str)
{
	size_t	i;

	i = 0;
	while (new_str[i])
	{
		free(new_str[i]);
		i++;
	}
	free(new_str);
	return (0);
}

size_t	find_column(char const *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			break ;
		i++;
	}
	return (i);
}

size_t	ft_strlcpy_new_str1(char *dst, char const *src, size_t size)
{
	size_t	count;
	size_t	i;

	count = 0;
	i = 0;
	if (dst == NULL || src == NULL)
		return (0);
	while (src[count] != '\0')
		count++;
	if (size != '\0')
	{
		while (src[i] != '\0' && i < size - 1)
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return ((size_t)count);
}
