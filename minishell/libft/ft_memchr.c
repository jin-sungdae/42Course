/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangcpar <sangcpar@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/06 04:26:41 by sangcpar          #+#    #+#             */
/*   Updated: 2020/10/06 04:28:20 by sangcpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *ptr, int c, size_t n)
{
	while (n--)
	{
		if (*(unsigned char *)ptr == (unsigned char)c)
			return ((void *)ptr);
		ptr++;
	}
	return (0);
}
