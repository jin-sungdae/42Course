#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	char			*big_1;
	char			*little_1;
	unsigned int	i;
	unsigned int	j;

	big_1 = (char*)big;
	little_1 = (char*)little;
	i = 0;
	if (*little_1 == '\0')
		return ((char*)big_1);
	while (big_1[i] != '\0' && i < len)
	{
		j = 0;
		while ((big_1[i + j] == little_1[j] && i + j < len))
		{
			j++;
			if (little_1[j] == '\0')
				return ((char*)&big_1[i]);
		}
		i++;
	}
	return (NULL);
}
