/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjin <sjin@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 20:25:54 by sjin              #+#    #+#             */
/*   Updated: 2021/03/10 20:25:56 by sjin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *ptr, int value, size_t num)
{
	unsigned int	i;
	unsigned char	*ptr_1;

	i = 0;
	ptr_1 = (unsigned char*)ptr;
	if (i == num)
		return (NULL);
	while (i < num)
	{
		if (ptr_1[i] == (unsigned char)value)
			return ((unsigned char *)&ptr_1[i]);
		i++;
	}
	return (0);
}
