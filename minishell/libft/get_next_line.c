/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangcpar <sangcpar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 21:04:45 by sangcpar          #+#    #+#             */
/*   Updated: 2020/11/04 14:10:45 by sangcpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"

int	get_next_line(const int fd, char **cmd)
{
	int		ret;
	char	buf;
	int		i;
	int		count;

	*cmd = ft_strnew(1);
	count = 1;
	(void)fd;
	i = 0;
	ret = read(0, &buf, 1);
	while (ret && buf != '\n')
	{
		*(*cmd + i++) = buf;
		*cmd = ft_realloc(*cmd, count, count + 1);
		count++;
		ret = read(0, &buf, 1);
	}
	*(*cmd + i) = '\0';
	if (!ret)
		return (-1);
	return (0);
}

int	free_retrurn(char **cpy, int fd)
{
	free(cpy[fd]);
	return (0);
}

int	get_next_line1(const int fd, char **line)
{
	static char	*cpy[10000];
	char		buf[BUFF_SIZE + 1];
	char		*tmp;
	int			rd_ret;

	if (!cpy[fd])
		cpy[fd] = ft_strnew(0);
	if (fd < 0 || !line || !cpy[fd] || (read(fd, buf, 0) < 0) || fd >= 10000)
		return (-1);
	rd_ret = read(fd, buf, 1);
	while (rd_ret > 0)
	{
		buf[rd_ret] = 0;
		tmp = ft_strjoin(cpy[fd], buf, 4);
		free(cpy[fd]);
		cpy[fd] = tmp;
		if (ft_strchr(buf, ENDL))
			break ;
		rd_ret = read(fd, buf, 1);
	}
	if (rd_ret < 0)
		return (-1);
	else if (!rd_ret && (!cpy[fd] || !cpy[fd][0]))
		return (free_retrurn(cpy, fd));
	return (ft_cleanup(cpy, line, fd, rd_ret));
}
