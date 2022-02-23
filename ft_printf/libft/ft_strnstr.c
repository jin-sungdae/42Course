/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjin <sjin@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 20:30:59 by sjin              #+#    #+#             */
/*   Updated: 2021/03/10 20:31:00 by sjin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	char			*big_1;
	char			*little_1;
	unsigned int	i;
	unsigned int	j;

	big_1 = (char*)big;
	little_1 = (char*)little;
	i = 0;
	if (*little_1 == '\0')
		return ((char*)big_1);
	while (big_1[i] != '\0' && i < len)
	{
		j = 0;
		while ((big_1[i + j] == little_1[j] && i + j < len))
		{
			j++;
			if (little_1[j] == '\0')
				return ((char*)&big_1[i]);
		}
		i++;
	}
	return (NULL);
}
