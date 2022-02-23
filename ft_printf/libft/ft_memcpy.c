/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjin <sjin@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 20:28:53 by sjin              #+#    #+#             */
/*   Updated: 2021/03/10 20:28:54 by sjin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t count)
{
	unsigned int	i;
	unsigned char	*dest1;
	unsigned char	*src1;

	if (dest == NULL && src == NULL)
		return (NULL);
	i = 0;
	dest1 = (unsigned char*)dest;
	src1 = (unsigned char*)src;
	while (i < count)
	{
		dest1[i] = src1[i];
		i++;
	}
	return (dest);
}
