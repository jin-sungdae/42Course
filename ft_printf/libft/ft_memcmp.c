#include "libft.h"

int	ft_memcmp(const void *ptr1, const void *ptr2, size_t num)
{
	unsigned int	i;
	unsigned char	*ptr1a;
	unsigned char	*ptr2a;

	i = 0;
	ptr1a = (unsigned char*)ptr1;
	ptr2a = (unsigned char*)ptr2;
	while (i < num)
	{
		if (ptr1a[i] != ptr2a[i])
			return (ptr1a[i] - ptr2a[i]);
		i++;
	}
	return (0);
}
