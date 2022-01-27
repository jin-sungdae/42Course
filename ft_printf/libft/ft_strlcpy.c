#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t num)
{
	size_t	count;
	size_t	i;

	count = 0;
	i = 0;
	if (dest == NULL || src == NULL)
		return (0);
	while (src[count] != '\0')
		count++;
	if (num != '\0')
	{
		while (src[i] != '\0' && i < num - 1)
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
	}
	return ((size_t)count);
}
