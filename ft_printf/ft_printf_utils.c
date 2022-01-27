#include "ft_printf.h"

void	all_zero(t_options *op)
{
	op->type = 0;
	op->width = 0;
	op->zero = 0;
	op->precision = -1;
	op->minus = 0;
	op->i_d_check = 0;
	op->nbr_base = 10;
	op->base = 96;
}

char	*ft_strjoin1(char *s1, char *s2)
{
	char	*new_str;
	int		len;

	len = ft_strlen(s1) + ft_strlen(s2);
	if (s1 == NULL || !(s1))
		return (NULL);
	if (!(new_str = (char*)malloc(sizeof(char) * len + 1)))
		return (NULL);
	ft_strcpy(new_str, s1);
	free(s1);
	ft_strcat(new_str, s2);
	return (new_str);
}

int		findlen_sixteen(long nb)
{
	int	i;

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
		nb = nb / 16;
		i++;
	}
	return (i);
}

int		find_len(long nb)
{
	int	i;

	i = 0;
	if (nb < 0)
	{
		nb = nb * -1;
		i++;
	}
	if (nb == 0)
		return (1);
	while (nb > 0)
	{
		nb = nb / 10;
		i++;
	}
	return (i);
}

void	m_s(unsigned long long nbr, t_options *op, int ret, char ****new_nbr)
{
	int i;

	if (op->type == 'X')
		op->base = 64;
	i = 1;
	while (nbr)
	{
		if ((nbr % 16) > 9)
		{
			(***new_nbr)[ret - i] = op->base + ((nbr % 16) - 9);
			nbr = nbr / 16;
		}
		else
		{
			(***new_nbr)[ret - i] = 48 + (nbr % 16);
			nbr = nbr / 16;
		}
		i++;
	}
}
