#include "libft.h"

void	*ft_calloc(size_t n, size_t size)
{
	void	*ptr;

	ptr = malloc(size * n);
	if (ptr == NULL)
		return (ptr);
	ft_bzero(ptr, (size * n));
	return (ptr);
}
