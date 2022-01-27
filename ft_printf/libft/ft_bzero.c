#include "libft.h"

void	ft_bzero(void *ptr, size_t n)
{
	unsigned char	*dest;
	size_t			i;

	i = 0;
	dest = (unsigned char*)ptr;
	while (i < n)
	{
		dest[i] = 0;
		i++;
	}
}
