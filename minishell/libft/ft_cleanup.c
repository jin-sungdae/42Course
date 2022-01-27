/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cleanup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangcpar <sangcpar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 07:21:47 by sangcpar          #+#    #+#             */
/*   Updated: 2021/06/01 07:21:49 by sangcpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_cleanup(char **cpy, char **line, int fd, int rd_ret)
{
	char	*tmp;
	size_t	len;

	len = ft_lentoc(cpy[fd], ENDL);
	if (cpy[fd][len] == ENDL)
	{
		*line = ft_strsub(cpy[fd], 0, len);
		tmp = ft_strdup(cpy[fd] + len + 1);
		free(cpy[fd]);
		cpy[fd] = tmp;
		if (!cpy[fd])
			ft_strdel(&cpy[fd]);
	}
	else if (!cpy[fd][len])
	{
		if (rd_ret == BUFF_SIZE)
			return (get_next_line(fd, line));
		*line = ft_strdup(cpy[fd]);
		ft_strdel(&cpy[fd]);
	}
	return (1);
}
