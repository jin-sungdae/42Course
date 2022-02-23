/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjin <sjin@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 11:52:26 by sjin              #+#    #+#             */
/*   Updated: 2020/12/27 20:32:33 by sjin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t count)
{
	unsigned int	i;
	unsigned char	*dest_1;
	unsigned char	*src_1;

	if (dest == NULL && src == NULL)
		return (NULL);
	i = 0;
	dest_1 = (unsigned char*)dest;
	src_1 = (unsigned char*)src;
	while (i < count)
	{
		dest_1[i] = src_1[i];
		i++;
	}
	return (dest);
}
