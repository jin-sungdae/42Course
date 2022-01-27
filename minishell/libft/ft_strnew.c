/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangcpar <sangcpar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 07:22:01 by sangcpar          #+#    #+#             */
/*   Updated: 2021/06/01 07:22:03 by sangcpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*new_string;

	new_string = (char *)malloc(sizeof(char) * size + 1);
	if (!new_string)
		return (NULL);
	ft_bzero(new_string, size + 1);
	return (new_string);
}
