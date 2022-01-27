/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjin <sjin@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 22:37:22 by sjin              #+#    #+#             */
/*   Updated: 2021/07/05 22:37:23 by sjin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static char	**malloc_free(char **new_str)
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

size_t	ft_strlcpy_new_str(char *dst, char const *src, size_t size)
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

char	**ft_split(char const *s, char c)
{
	char	**new_str;
	size_t	index[3];

	if (s[0] == '\0')
		return (0);
	index[1] = find_row(s, c);
	new_str = (char **)malloc(sizeof(char *) * (index[1]) + 1);
	if (!new_str)
		return (0);
	index[2] = 0;
	while (index[2] < index[1])
	{
		while (*s && *s == c)
			s++;
		index[0] = find_column(s, c);
		new_str[index[2]] = (char *)malloc(sizeof(char) * (index[0] + 1));
		if (!new_str[index[2]])
			return (malloc_free(new_str));
		ft_strlcpy_new_str(new_str[index[2]], s, index[0] + 1);
		index[2]++;
		if (index[2] < index[1])
			s += index[0];
	}
	new_str[index[2]] = NULL;
	return (new_str);
}
