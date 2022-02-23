/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjin <sjin@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/27 17:37:06 by sjin              #+#    #+#             */
/*   Updated: 2020/12/27 21:09:24 by sjin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	len;
	char			*new_str;

	i = 0;
	j = 0;
	len = ft_strlen((char*)s1) + ft_strlen((char*)s2);
	if (s1 == 0 || s2 == 0)
		return (NULL);
	if (!(new_str = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	while (i < len && s1[i] != '\0')
	{
		new_str[i] = s1[i];
		i++;
	}
	while (i + j < len && s2[j] != '\0')
	{
		new_str[i + j] = s2[j];
		j++;
	}
	new_str[i + j] = '\0';
	return (new_str);
}
