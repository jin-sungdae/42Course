/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjin <sjin@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 20:27:19 by sjin              #+#    #+#             */
/*   Updated: 2021/03/10 20:27:21 by sjin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *ptr1, const void *ptr2, size_t num)
{
	unsigned int	i;
	unsigned char	*ptr1a;
	unsigned char	*ptr2a;

	i = 0;
	ptr1a = (unsigned char*)ptr1;
	ptr2a = (unsigned char*)ptr2;
	while (i < num)
	{
		if (ptr1a[i] != ptr2a[i])
			return (ptr1a[i] - ptr2a[i]);
		i++;
	}
	return (0);
}
