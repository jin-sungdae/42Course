/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangcpar <sangcpar@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/06 01:35:26 by sangcpar          #+#    #+#             */
/*   Updated: 2020/10/14 01:28:00 by sangcpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	len;
	char	*str;
	char	find;

	find = (char)c;
	str = (char *)s;
	len = ft_strlen(s);
	while (len > 0)
	{
		if (str[len] == find)
			return (str + len);
		len--;
	}
	if (str[len] == find)
		return (str);
	return (0);
}
