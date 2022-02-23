/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjin <sjin@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 11:55:27 by sjin              #+#    #+#             */
/*   Updated: 2020/12/27 17:23:17 by sjin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t num)
{
	size_t	count;
	size_t	i;

	count = 0;
	i = 0;
	if (dest == NULL || src == NULL)
		return (0);
	while (src[count] != '\0')
		count++;
	if (num != '\0')
	{
		while (src[i] != '\0' && i < num - 1)
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
	}
	return ((size_t)count);
}
