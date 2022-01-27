/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangcpar <sangcpar@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 23:44:29 by sangcpar          #+#    #+#             */
/*   Updated: 2020/10/10 10:39:46 by sangcpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	find;

	i = 0;
	if (!s)
		return (NULL);
	find = (unsigned char)c;
	while (s[i])
	{
		if (s[i] == find)
			return ((char *)(s + i));
		i++;
	}
	if (s[i] == find)
		return ((char *)(s + i));
	return (NULL);
}
