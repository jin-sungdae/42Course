#include "libft.h"

int	find_third_column(char *s)
{
	int	i;

	i = 0;
	s[0] = '\\';
	while (s[i])
		i++;
	s[i - 2] = '\\';
	s[i - 1] = '\"';
	return (i);
}

int	find_second_column(char *s)
{
	int		i;
	int		check;
	char	temp;

	check = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] == '\"' && s[i + 1] == '\'')
		{
			temp = s[i];
			s[i] = s[i + 1];
			s[i + 1] = temp;
			i += 1;
		}
		else if (s[i] == '\'' && s[i + 1] == '\"')
		{
			temp = s[i];
			s[i] = s[i + 1];
			s[i + 1] = temp;
			i += 1;
		}
		i++;
	}
	return (i - 2);
}

int	check_all_line(char **s, char c)
{
	int	i;

	i = 0;
	if (**s == '\'' && *s[1] != '\"')
	{
		i = find_new_column(*s);
		(*s)++;
	}
	else if (**s == '\"' && *s[1] == '\'')
	{
		i = find_second_column(*s);
		s++;
	}
	else if (*s[0] == '\'' && *s[1] == '\"')
		i = find_third_column(*s);
	else
		i = find_column(*s, c);
	return (i);
}

void	oo(char *s, char c, char **new_str, int index[])
{
	while (index[2] < index[1])
	{
		while (*s && *s == c)
			s++;
		if (*s == '\'' && s[1] != '\"')
			index[0] = find_new_column(s++);
		else if (*s == '\"' && s[1] == '\'')
			index[0] = find_second_column(s++);
		else if (s[0] == '\'' && s[1] == '\"')
			index[0] = find_third_column(s);
		else
			index[0] = find_column(s, c);
		new_str[index[2]] = (char *)malloc(sizeof(char) * (index[0] + 1));
		if (!new_str[index[2]])
			malloc_free(new_str);
		ft_strlcpy_new_str1(new_str[index[2]++], s, index[0] + 1);
		if (index[2] < index[1])
			s += index[0];
	}
}

char	**ft_split2(char *s, char c)
{
	char	**new_str;
	int		index[3];

	if (s[0] == '\0')
		return (0);
	index[1] = check_row(s, c);
	new_str = (char **)malloc(sizeof(char *) * (index[1]) + 1);
	if (!new_str)
		return (0);
	index[2] = 0;
	oo (s, c, new_str, index);
	new_str[index[2]] = NULL;
	return (new_str);
}
