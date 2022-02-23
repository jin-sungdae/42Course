/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjin <sjin@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 11:51:47 by sjin              #+#    #+#             */
/*   Updated: 2020/12/27 21:05:30 by sjin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *ptr, int value, size_t num)
{
	unsigned char	*dest;
	size_t			i;

	i = 0;
	dest = (unsigned char*)ptr;
	while (i < num)
	{
		dest[i] = value;
		i++;
	}
	return (dest);
}
