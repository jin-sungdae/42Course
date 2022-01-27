/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangcpar <sangcpar@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/06 03:55:33 by sangcpar          #+#    #+#             */
/*   Updated: 2020/10/06 04:09:17 by sangcpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned char	*n_dest;
	unsigned char	*n_src;
	unsigned char	find;
	size_t			i;

	n_dest = dest;
	n_src = (unsigned char *)src;
	find = c;
	i = 0;
	while (i < n)
	{
		n_dest[i] = n_src[i];
		if (n_src[i] == find)
			return (dest + (i + 1));
		i++;
	}
	return (0);
}
