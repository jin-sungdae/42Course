#include "libft.h"

char	*ft_strcpy(char *s1, char *s2)
{
	int i;

	i = 0;
	while (i < ft_strlen(s2))
	{
		s1[i] = s2[i];
		i++;
	}
	s1[i] = s2[i];
	return (s1);
}
