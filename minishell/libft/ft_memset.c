/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangcpar <sangcpar@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/01 12:50:28 by sangcpar          #+#    #+#             */
/*   Updated: 2020/10/13 20:51:27 by sangcpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *dst, int val, size_t size)
{
	size_t			i;
	unsigned char	*n_dst;

	i = 0;
	n_dst = (unsigned char *)dst;
	while (i < size)
	{
		n_dst[i] = (unsigned char)val;
		i++;
	}
	return (dst);
}
