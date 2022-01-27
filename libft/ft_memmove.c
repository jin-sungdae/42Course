#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t count)
{
	unsigned char	*dest_1;
	unsigned char	*src_1;
	size_t			i;

	i = 0;
	dest_1 = (unsigned char*)dest;
	src_1 = (unsigned char*)src;
	if (!dest && !src)
		return (NULL);
	if (dest > src)
	{
		while (count--)
			dest_1[count] = src_1[count];
	}
	else
	{
		while (i < count)
		{
			dest_1[i] = src_1[i];
			i++;
		}
	}
	return (dest);
}
