#include "libft.h"

int		findlen_sixteen(long nb, int base)
{
	int i;

	i = 0;
	if (nb < 0)
	{
		nb = -nb;
		i++;
	}
	if (nb == 0)
		return (1);
	while (nb > 0)
	{
		nb = nb / base;
		i++;
	}
	return (i);
}

char	*ft_itoa_base(long long nb, int base)
{
	int				size;
	long			nbr;
	char			*result;
	char			*ref_base;

	nbr = nb;
	ref_base = "0123456789ABCDEF";
	if (base < 2 || base > 16)
		return (NULL);
	size = findlen_sixteen(nbr, base);
	if (!(result = (char*)malloc(sizeof(*result) * (size + 1))))
		return (NULL);
	result[size--] = '\0';
	result[0] = (nb < 0 ? '-' : '0');
	if (nb < 0)
		nbr = -nbr;
	while (nbr > 0)
	{
		result[size--] = ref_base[nbr % base];
		nbr /= base;
	}
	return (result);
}
