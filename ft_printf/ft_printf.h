#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include "./libft/libft.h"

# define TYPE "csidupxX%"

typedef struct	s_option
{
	char		type;
	int			minus;
	int			zero;
	int			width;
	int			i_d_check;
	int			precision;
	int			nbr_base;
	int			base;
}				t_options;

void	flag(char *str, t_options *op, va_list ap, int i);
int		find_form(va_list ap, t_options *op);
int		ft_printf_function(char *format, va_list ap);
int		ft_printf(const char *format, ...);
void	flag_width_precision(char *str, t_options *op, va_list ap, int i);

int		width_print_char(int width, int len, int zero);
int		width_print_str(char **str, t_options *op, int str_len);
int		nbr_2(t_options *op, unsigned long long nbr, int len, char ***new_nbr);
int		nbr_1(t_options *op, unsigned long long nbr, int len, char ***new_nbr);
int		minus_function(char **new_nbr, t_options *op, int ret);

int		print_char(int c, t_options *op);
int		nbr_make_str(unsigned long long nbr, char **new_nbr, t_options *op);
int		print_nbr(unsigned long long nbr, t_options *op);
char	*new_str_function(char *str, int precision, int len);
int		print_string(char *str, t_options *op);

int		findlen_sixteen(long nb);
int		find_len(long nb);
char	*ft_strjoin1(char *s1, char *s2);
void	all_zero(t_options *op);
void	m_s(unsigned long long nbr, t_options *op, int ret, char ****new_nbr);

#endif
