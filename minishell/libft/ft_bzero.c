/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangcpar <sangcpar@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/01 13:06:15 by sangcpar          #+#    #+#             */
/*   Updated: 2020/10/10 10:11:39 by sangcpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *dst, size_t size)
{
	size_t			i;
	unsigned char	*n_dst;

	n_dst = dst;
	i = 0;
	while (i < size)
	{
		n_dst[i] = 0;
		i++;
	}
}
