#include "libft.h"

char	*ft_strcat(char *s1, char *s2)
{
	int i;
	int j;

	j = 0;
	i = 0;
	while (i < ft_strlen(s1))
		i++;
	while (j < ft_strlen(s2))
	{
		s1[i + j] = s2[j];
		j++;
	}
	s1[i + j] = '\0';
	return (s1);
}
