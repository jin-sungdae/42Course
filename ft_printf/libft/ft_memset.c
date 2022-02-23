/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjin <sjin@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 20:26:01 by sjin              #+#    #+#             */
/*   Updated: 2021/03/10 20:26:02 by sjin             ###   ########.fr       */
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
