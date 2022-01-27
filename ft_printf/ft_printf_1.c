#include "ft_printf.h"

int		minus_function(char **new_nbr, t_options *op, int ret)
{
	int	ret2;

	ret2 = 0;
	if (op->i_d_check == 1 && op->zero == 1)
	{
		if (ret >= op->width)
		{
			*new_nbr = ft_strjoin("-", *new_nbr);
			ret2 = 1;
		}
		else if (ret < op->width)
			*new_nbr[0] = '-';
	}
	return (ret2);
}

int		width_print_char(int width, int len, int zero)
{
	int	ret;

	ret = 0;
	while (len < width)
	{
		if (zero == 1)
			ft_putchar('0');
		else
			ft_putchar(' ');
		len++;
		ret++;
	}
	return (ret);
}

int		width_print_str(char **str, t_options *op, int str_len)
{
	char	*minus_flag;
	int		i;
	int		len;

	if (op->width <= str_len)
		return (str_len);
	len = op->width - str_len;
	i = 0;
	if (len < 0)
		len = len * -1;
	if (!(minus_flag = (char*)malloc(sizeof(char) * len + 1)))
		return (0);
	while (len-- > 0)
	{
		if (op->zero)
			minus_flag[i++] = '0';
		else if (op->zero == 0)
			minus_flag[i++] = ' ';
	}
	minus_flag[i] = '\0';
	if (op->minus == 0)
		*str = ft_strjoin(minus_flag, *str);
	else if (op->minus)
		*str = ft_strjoin1(*str, minus_flag);
	return (op->width);
}

int		nbr_2(t_options *op, unsigned long long nbr, int len, char ***new_nbr)
{
	int	ret;
	int	i;

	ret = (op->precision > len) ? op->precision : len;
	if (!(**new_nbr = (char*)malloc(sizeof(char) * ret + 1)))
		return (0);
	i = 0;
	(**new_nbr)[ret] = '\0';
	while (len + i < ret)
	{
		(**new_nbr)[i] = '0';
		i++;
	}
	i = 1;
	if (nbr == 0 && op->precision != 0)
		(**new_nbr)[ret - i] = '0';
	if (nbr == 0 && op->precision == 0)
		(**new_nbr)[0] = '\0';
	m_s(nbr, op, ret, &new_nbr);
	return (len);
}

int		nbr_1(t_options *op, unsigned long long nbr, int len, char ***new_nbr)
{
	int ret;
	int i;

	i = 0;
	ret = (op->precision > len) ? op->precision : len;
	if (!(**new_nbr = (char*)malloc(sizeof(char) * ret + 1)))
		return (0);
	(**new_nbr)[ret] = '\0';
	while (len + i < ret)
	{
		(**new_nbr)[i] = '0';
		i++;
	}
	i = 1;
	if (nbr == 0 && op->precision != 0)
		(**new_nbr)[ret - i] = '0';
	if (nbr == 0 && op->precision == 0)
		(**new_nbr)[0] = '\0';
	while (nbr)
	{
		(**new_nbr)[ret - i] = 48 + (nbr % 10);
		nbr = nbr / 10;
		i++;
	}
	return (len);
}
