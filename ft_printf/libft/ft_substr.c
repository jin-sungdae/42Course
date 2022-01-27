#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*new_s;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (s == 0)
		return (NULL);
	if (!(new_s = (char*)malloc(sizeof(char) * (len + 1))))
		return (0);
	if (!new_s)
		return (NULL);
	while (s[i] != '\0')
	{
		if (i >= start && j < len)
		{
			new_s[j] = s[i];
			j++;
		}
		i++;
	}
	new_s[j] = 0;
	return (new_s);
}
