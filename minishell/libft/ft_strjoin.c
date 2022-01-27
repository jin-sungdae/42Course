/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangcpar <sangcpar@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/06 23:24:26 by sangcpar          #+#    #+#             */
/*   Updated: 2020/10/10 10:27:47 by sangcpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	fr_chk(char **s1, char **s2, int f)
{
	if (f == 1)
		free(*s1);
	if (f == 2)
		free(*s2);
	if (f == 3)
	{
		free(*s1);
		free(*s2);
	}
}

char	*ft_strjoin(char *s1, char *s2, int f)
{
	char	*str;
	size_t	i;
	size_t	j;

	if (!s2)
		return (NULL);
	str = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!str)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		str[i] = s2[j];
		i++;
		j++;
	}
	str[i] = '\0';
	fr_chk(&s1, &s2, f);
	return (str);
}
