/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjin <sjin@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 11:54:36 by sjin              #+#    #+#             */
/*   Updated: 2020/12/27 21:03:47 by sjin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *ptr1, const void *ptr2, size_t num)
{
	unsigned int	i;
	unsigned char	*ptr1_a;
	unsigned char	*ptr2_a;

	i = 0;
	ptr1_a = (unsigned char*)ptr1;
	ptr2_a = (unsigned char*)ptr2;
	while (i < num)
	{
		if (ptr1_a[i] != ptr2_a[i])
			return (ptr1_a[i] - ptr2_a[i]);
		i++;
	}
	return (0);
}
