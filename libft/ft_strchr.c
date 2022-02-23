/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjin <sjin@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 11:55:55 by sjin              #+#    #+#             */
/*   Updated: 2020/12/27 21:07:14 by sjin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	size_t	i;
	char	*str_1;

	str_1 = (char*)str;
	i = 0;
	while (str_1[i] != '\0')
	{
		if (str_1[i] == (unsigned char)c)
			return (&str_1[i]);
		i++;
	}
	if (str_1[i] == (unsigned char)c)
		return ((char*)str_1 + i);
	return (0);
}
