/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjin <sjin@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 11:56:06 by sjin              #+#    #+#             */
/*   Updated: 2020/12/27 19:50:32 by sjin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	char	*str_1;
	size_t	i;

	str_1 = (char*)str;
	i = ft_strlen(str_1);
	while (i > 0)
	{
		if (str_1[i] == (unsigned char)c)
			return (&str_1[i]);
		i--;
	}
	if (str_1[0] == (unsigned char)c)
		return ((char*)str_1);
	return (NULL);
}
