/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangcpar <sangcpar@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/02 19:13:10 by sangcpar          #+#    #+#             */
/*   Updated: 2020/10/10 10:35:44 by sangcpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t size)
{
	unsigned char	*tmp;
	unsigned char	*s;

	if (dest == src || size == 0)
		return (dest);
	if (dest <= src)
	{
		tmp = (unsigned char *)dest;
		s = (unsigned char *)src;
		while (size--)
			*tmp++ = *s++;
	}
	else
	{
		tmp = (unsigned char *)dest + (size - 1);
		s = (unsigned char *)src + (size - 1);
		while (size--)
			*tmp-- = *s--;
	}
	return (dest);
}
