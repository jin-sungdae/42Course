/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangcpar <sangcpar@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/03 02:59:08 by sangcpar          #+#    #+#             */
/*   Updated: 2020/10/13 22:36:37 by sangcpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dst_len;
	size_t	res;
	int		i;
	int		j;

	dst_len = ft_strlen(dst);
	res = ft_strlen(src);
	i = 0;
	j = dst_len;
	if (size < dst_len)
		return (res + size);
	while ((src[i] != '\0') && i < (int)(size - dst_len - 1))
	{
		dst[j] = src[i];
		i++;
		j++;
	}
	dst[j] = '\0';
	return (res + dst_len);
}
