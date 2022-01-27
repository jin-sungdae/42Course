/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangcpar <sangcpar@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/06 04:36:04 by sangcpar          #+#    #+#             */
/*   Updated: 2020/10/06 04:39:44 by sangcpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t n)
{
	size_t	len;

	if (*little == '\0')
		return ((char *)big);
	len = ft_strlen(little);
	while (*big && len <= n--)
	{
		if (!ft_strncmp(big, little, len))
			return ((char *)big);
		big++;
	}
	return (0);
}
