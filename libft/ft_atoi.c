/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjin <sjin@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 11:56:48 by sjin              #+#    #+#             */
/*   Updated: 2020/12/28 01:29:21 by sjin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int						i;
	int						sign;
	unsigned long long		number;

	i = 0;
	sign = 1;
	number = 0;
	while ((str[i] == ' ' || str[i] == '\n' || str[i] == '\t' ||
		str[i] == '\r' || str[i] == '\v' || str[i] == '\f'))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] != '\0' && str[i] >= '0' && str[i] <= '9')
	{
		number *= 10;
		number += str[i] - '0';
		i++;
	}
	if (i > 19 || number >= 9223372036854775808ULL)
		return (sign == 1 ? -1 : 0);
	return (number * sign);
}
