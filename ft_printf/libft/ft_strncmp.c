/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjin <sjin@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 20:29:32 by sjin              #+#    #+#             */
/*   Updated: 2021/03/10 20:29:33 by sjin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*s1_1;
	unsigned char	*s2_1;

	i = 0;
	s1_1 = (unsigned char*)s1;
	s2_1 = (unsigned char*)s2;
	while (s1_1[i] && s2_1[i] && i < n)
	{
		if (s1_1[i] != s2_1[i])
			return (s1_1[i] - s2_1[i]);
		i++;
	}
	if (i != n)
		return (s1_1[i] - s2_1[i]);
	return (0);
}
