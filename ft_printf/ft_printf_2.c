/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjin <sjin@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 20:25:14 by sjin              #+#    #+#             */
/*   Updated: 2021/03/10 20:25:18 by sjin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		print_char(int c, t_options *op)
{
	int	ret;

	ret = 0;
	if (op->type == '%' && op->minus == 1)
		op->zero = 0;
	if (op->minus == 1)
		ret += ft_putchar(c);
	ret += width_print_char(op->width, 1, op->zero);
	if (op->minus == 0)
		ret += ft_putchar(c);
	return (ret);
}

int		nbr_make_str(unsigned long long nbr, char **new_nbr, t_options *op)
{
	int	ret;

	ret = 0;
	if (op->type == 'x' || op->type == 'X' || op->type == 'p')
	{
		ret += nbr_2(op, nbr, findlen_sixteen(nbr), &new_nbr);
		if (op->type == 'p')
		{
			ret += nbr_2(op, nbr, findlen_sixteen(nbr), &new_nbr) + 2;
			*new_nbr = ft_strjoin("0x", *new_nbr);
		}
	}
	else if (op->type == 'u' || op->type == 'i' || op->type == 'd')
		ret += nbr_1(op, nbr, find_len(nbr), &new_nbr);
	return (ret);
}

int		print_nbr(unsigned long long nbr, t_options *op)
{
	char	*new_nbr_num;
	int		ret;

	ret = 0;
	if ((op->type == 'd' || op->type == 'i') && (int)nbr < 0)
	{
		op->i_d_check = 1;
		nbr = -1 * nbr;
	}
	ret = nbr_make_str(nbr, &new_nbr_num, op);
	if ((op->type == 'i' || op->type == 'd') && op->zero == 0 && op->i_d_check)
	{
		new_nbr_num = ft_strjoin("-", new_nbr_num);
		ret += 1;
	}
	if (op->precision == -1 || op->precision > ft_strlen(new_nbr_num)
			|| (op->width >= op->precision))
		op->precision = ft_strlen(new_nbr_num);
	if ((op->i_d_check && op->zero))
		op->width--;
	ret = width_print_str(&new_nbr_num, op, ft_strlen(new_nbr_num));
	ret += minus_function(&new_nbr_num, op, ret);
	ft_putstr(new_nbr_num);
	free(new_nbr_num);
	return (ret);
}

char	*new_str_function(char *str, int precision, int len)
{
	char	*new_str;
	int		i;

	i = 0;
	if (precision < 0)
		precision = precision >= len ? precision : len;
	else
		precision = precision < len ? precision : len;
	if (!(new_str = (char*)malloc(sizeof(char) * precision + 1)))
		return (NULL);
	while (i < precision)
	{
		new_str[i] = str[i];
		i++;
	}
	new_str[i] = '\0';
	return (new_str);
}

int		print_string(char *str, t_options *op)
{
	char		*new_str;
	int			ret;

	ret = 0;
	if (str == NULL)
		str = "(null)";
	if (op->precision == -1 || (op->precision > ft_strlen(str)))
		op->precision = ft_strlen(str);
	new_str = new_str_function(str, op->precision, ft_strlen(str));
	ret = width_print_str(&new_str, op, ft_strlen(new_str));
	ft_putstr(new_str);
	free(new_str);
	return (ret);
}
