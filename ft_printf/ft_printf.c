#include "ft_printf.h"

void	flag_width_precision(char *str, t_options *op, va_list ap, int i)
{
	if (str[i] == '*')
	{
		if (op->precision == -1)
		{
			op->width = va_arg(ap, int);
			if (op->width < 0)
			{
				op->minus = 1;
				op->width *= -1;
			}
		}
		else
			op->precision = va_arg(ap, int);
	}
	else if (ft_isdigit(str[i]))
	{
		if (op->precision == -1)
			op->width = op->width * 10 + str[i] - 48;
		else
			op->precision = op->precision * 10 + str[i] - 48;
	}
}

void	flag(char *str, t_options *op, va_list ap, int i)
{
	if (str[i] == '0' && op->width == 0 && op->precision == -1)
		op->zero = 1;
	else if (str[i] == '-')
		op->minus = 1;
	else if (str[i] == '.')
		op->precision = 0;
	else if (str[i] == '*' || ft_isdigit(str[i]))
		flag_width_precision(str, op, ap, i);
	else
		ft_putchar(str[i]);
}

int		find_form(va_list ap, t_options *op)
{
	char	type;
	int		ret;

	ret = 0;
	type = op->type;
	if (op->type == 'c')
		ret += print_char(va_arg(ap, int), op);
	else if (op->type == '%')
		ret += print_char('%', op);
	else if (op->type == 's')
		ret += print_string(va_arg(ap, char *), op);
	else if (op->type == 'i' || op->type == 'd')
		ret += print_nbr(va_arg(ap, int), op);
	else if (op->type == 'x' || op->type == 'X' || op->type == 'u')
		ret += print_nbr(va_arg(ap, unsigned int), op);
	else if (op->type == 'p')
		ret += print_nbr(va_arg(ap, unsigned long long), op);
	return (ret);
}

int		ft_printf_function(char *format, va_list ap)
{
	int			i;
	int			ret;
	t_options	*op;

	if (!(op = malloc(sizeof(t_options))))
		return (-1);
	i = 0;
	ret = 0;
	while (format[i] != '\0')
	{
		while (format[i] != '%' && format[i] != '\0')
			ret += ft_putchar(format[i++]);
		if (format[i] == '%')
		{
			all_zero(op);
			while (format[++i] != '\0' && !(ft_strchr(TYPE, format[i])))
				flag(format, op, ap, i);
			op->type = format[i++];
			if ((op->minus == 1 || op->precision > -1) && op->type != '%')
				op->zero = 0;
			ret += find_form(ap, op);
		}
	}
	free(op);
	return (ret);
}

int		ft_printf(const char *format, ...)
{
	int			i;
	va_list		ap;

	va_start(ap, format);
	i = ft_printf_function((char*)format, ap);
	va_end(ap);
	return (i);
}
