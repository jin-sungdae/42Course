/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjin <sjin@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 20:26:13 by sjin              #+#    #+#             */
/*   Updated: 2021/03/10 20:26:14 by sjin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		**malloc_free(char **new_str)
{
	size_t	i;

	i = 0;
	while (new_str[i])
	{
		free(new_str[i]);
		i++;
	}
	free(new_str);
	return (0);
}

static size_t	find_row(char const *s, char c)
{
	size_t	row;
	size_t	i;

	row = 0;
	i = 0;
	if (s[0] == '\0')
		return (0);
	while (s[i] && s[i] == c)
		i++;
	while (s[i] != '\0')
	{
		if (s[i] == c)
		{
			row++;
			while (s[i] && s[i] == c)
				i++;
		}
		else
			i++;
	}
	if (s[i - 1] != c)
		row++;
	return (row);
}

static size_t	find_column(char const *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			break ;
		i++;
	}
	return (i);
}

size_t			ft_strlcpy_new_str(char *dst, char const *src, size_t size)
{
	size_t	count;
	size_t	i;

	count = 0;
	i = 0;
	if (dst == NULL || src == NULL)
		return (0);
	while (src[count] != '\0')
		count++;
	if (size != '\0')
	{
		while (src[i] != '\0' && i < size - 1)
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return ((size_t)count);
}

char			**ft_split(char const *s, char c)
{
	char	**new_str;
	size_t	len;
	size_t	row;
	size_t	i;

	if (s[0] == '\0')
		return (0);
	row = find_row(s, c);
	if (!(new_str = (char**)malloc(sizeof(char*) * (row + 1))))
		return (0);
	i = 0;
	while (i < row)
	{
		while (*s && *s == c)
			s++;
		len = find_column(s, c);
		if (!(new_str[i] = (char*)malloc(sizeof(char) * (len + 1))))
			return (malloc_free(new_str));
		ft_strlcpy_new_str(new_str[i], s, len + 1);
		i++;
		if (i < row)
			s += len;
	}
	new_str[i] = NULL;
	return (new_str);
}
