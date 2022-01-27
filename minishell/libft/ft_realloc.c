/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangcpar <sangcpar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 01:11:53 by sangcpar          #+#    #+#             */
/*   Updated: 2021/09/28 18:35:30 by sangcpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_realloc(void *ptr, size_t prev_size, size_t new_size)
{
	void	*new;

	if (!ptr)
		return (NULL);
	new = ft_memalloc(new_size);
	if (!new)
	{
		free(ptr);
		return (NULL);
	}
	if (prev_size < new_size)
		ft_memcpy(new, ptr, prev_size);
	else
		ft_memcpy(new, ptr, new_size);
	free(ptr);
	return (new);
}
