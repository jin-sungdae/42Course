/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   out_put_information.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjin <sjin@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 22:38:33 by sjin              #+#    #+#             */
/*   Updated: 2021/07/05 22:38:35 by sjin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

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

void	display_moves(t_info *info)
{
	ft_putnbr(info->moves);
	write(1, "\n", 1);
}
