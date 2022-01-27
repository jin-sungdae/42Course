#include "libft.h"

static int	find_char(char const *set, char c)
{
	size_t	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char		*ft_strtrim(char const *s, char const *set)
{
	char	*new_s;
	size_t	i;
	size_t	start;
	size_t	end;

	start = 0;
	while (s[start] && find_char(set, s[start]))
		start++;
	end = ft_strlen((char*)s);
	while (end > start && find_char(set, s[end - 1]))
		end--;
	new_s = (char*)malloc(sizeof(char) * (end - start + 1));
	if (new_s == NULL)
		return (0);
	i = 0;
	while (start < end)
	{
		new_s[i] = s[start];
		i++;
		start++;
	}
	new_s[i] = '\0';
	return (new_s);
}
