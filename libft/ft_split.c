/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjin <sjin@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/27 17:47:41 by sjin              #+#    #+#             */
/*   Updated: 2020/12/28 11:41:17 by sjin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void			**malloc_free(char **new_str, size_t count)
{
	unsigned int	i;

	i = 0;
	while (i < count)
	{
		free(new_str[i]);
		i++;
	}
	free(new_str);
	return (0);
}

size_t				find_row(const char *str, char c)
{
	size_t	i;
	size_t	row;

	i = 0;
	row = 0;
	while (str[i] != 0)
	{
		if (str[i] != c && str[i] != 0)
		{
			row++;
			while (str[i] != c && str[i] != 0)
				i++;
		}
		else if (str[i] != 0)
			i++;
	}
	return (row);
}

void				my_strcpy(char *dst, char const *src, int start, int last)
{
	int i;

	i = 0;
	while (start < last)
	{
		dst[i] = src[start];
		i++;
		start++;
	}
	dst[i] = 0;
}

static void			make_new_str(char const *s, char c, char **str)
{
	size_t	i;
	size_t	j;
	size_t	start;

	i = 0;
	j = 0;
	while (s[i] != 0)
	{
		if (s[i] != c && s[i] != 0)
		{
			start = i;
			while (s[i] != c && s[i] != 0)
				i++;
			if ((str[j] = (char *)malloc(sizeof(char) * (i - start + 1))) == 0)
			{
				malloc_free(str, j);
				return ;
			}
			my_strcpy(str[j], s, start, i);
			j++;
		}
		else if (s[i] != '\0')
			i++;
	}
}

char				**ft_split(char const *s, char c)
{
	char	**str;
	size_t	i;

	if (s == 0)
		return (0);
	i = find_row(s, c);
	str = (char **)malloc(sizeof(char *) * (i + 1));
	if (str == 0)
		return (0);
	str[i] = 0;
	if (i == 0)
		return (str);
	make_new_str(s, c, str);
	return (str);
}
