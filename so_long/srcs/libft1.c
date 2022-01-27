/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjin <sjin@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 22:37:02 by sjin              #+#    #+#             */
/*   Updated: 2021/07/05 22:37:09 by sjin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	else
		return (0);
}

char	*ft_strdup(const char *s)
{
	size_t	i;
	size_t	len;
	char	*str;

	i = 0;
	len = 0;
	len = ft_strlen((char *)s);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	while (i < len)
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	unsigned int	index[3];
	char			*new_str;

	index[0] = 0;
	index[2] = ft_strlen((char *)s1) + ft_strlen((char *)s2);
	if (s1 == 0 || s2 == 0)
		return (NULL);
	new_str = (char *)malloc(sizeof(char) * index[2] + 1);
	if (!new_str)
		return (NULL);
	while (index[0] < index[2] && s1[index[0]] != '\0')
	{
		new_str[index[0]] = s1[index[0]];
		index[0]++;
	}
	index[1] = 0;
	while (index[0] + index[1] < index[2] && s2[index[1]] != '\0')
	{
		new_str[index[0] + index[1]] = s2[index[1]];
		index[1]++;
	}
	new_str[index[0] + index[1]] = '\0';
	return (new_str);
}

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

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}
