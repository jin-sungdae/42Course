/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangcpar <sangcpar@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/01 13:17:07 by sangcpar          #+#    #+#             */
/*   Updated: 2020/10/10 10:15:12 by sangcpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t size)
{
	size_t			i;
	unsigned char	*n_dest;
	unsigned char	*n_src;

	if (!dest && !src)
		return (NULL);
	n_dest = dest;
	n_src = (unsigned char *)src;
	i = 0;
	while (i < size)
	{
		n_dest[i] = n_src[i];
		i++;
	}
	return (dest);
}
