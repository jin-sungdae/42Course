/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjin <sjin@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 11:59:01 by sjin              #+#    #+#             */
/*   Updated: 2020/12/27 20:42:19 by sjin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t n, size_t size)
{
	void *ptr;

	ptr = malloc(size * n);
	if (ptr == NULL)
		return (ptr);
	ft_bzero(ptr, (size * n));
	return (ptr);
}
