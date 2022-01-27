#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	size_t	i;
	char	*str_1;

	i = 0;
	str_1 = (char*)str;
	while (str_1[i] != '\0')
	{
		if (str_1[i] == (unsigned char)c)
			return (&str_1[i]);
		i++;
	}
	if (str_1[i] == (unsigned char)c)
		return ((char*)str_1 + i);
	return (0);
}
