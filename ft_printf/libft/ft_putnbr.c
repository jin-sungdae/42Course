#include "libft.h"

void	ft_putnbr(int nb)
{
	char	nb_arry[10];
	long	nb_change;
	int		i;

	i = 0;
	nb_change = nb;
	if (nb == 0)
		ft_putchar('0');
	else if (nb < 0)
	{
		ft_putchar('-');
		nb_change = -nb_change;
	}
	while (i < 10)
	{
		nb_arry[i] = nb_change % 10;
		nb_change = nb_change / 10;
		i++;
		if (nb_change == 0)
			break ;
	}
	while (i--)
		ft_putchar(nb_arry[i] + '0');
}
