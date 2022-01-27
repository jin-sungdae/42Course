/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjin <sjin@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 00:29:55 by sjin              #+#    #+#             */
/*   Updated: 2021/07/06 00:29:57 by sjin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	make_one_str(char **backup, char **line, int find_index)
{
	char	*tmp;
	int		len;

	(*backup)[find_index] = '\0';
	*line = ft_strdup1(*backup);
	len = ft_strlen1(*backup + find_index + 1);
	if (len == 0)
	{
		free(*backup);
		*backup = 0;
		return (1);
	}
	tmp = ft_strdup1(*backup + find_index + 1);
	free(*backup);
	*backup = tmp;
	return (1);
}

int	find_index_function(char *backup)
{
	int	i;

	i = 0;
	while (backup[i] != '\0')
	{
		if (backup[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

int	find_next_line(int buf_len, char **backup, char **line)
{
	int	find_index;

	if (buf_len < 0)
		return (-1);
	else if (*backup)
	{
		find_index = find_index_function(*backup);
		if (find_index >= 0)
			return (make_one_str(backup, line, find_index));
		else
		{
			*line = *backup;
			*backup = 0;
			return (0);
		}
	}
	*line = ft_strdup1("");
	return (0);
}

int	get_next_line(int fd, char **line)
{
	static char		*backup[OPEN_MAX];
	char			buf[BUFFER_SIZE + 1];
	int				buf_len;
	int				find_index;

	if ((fd < 0) || (line == NULL) || (BUFFER_SIZE <= 0))
		return (-1);
	buf_len = read(fd, buf, BUFFER_SIZE);
	while (buf_len > 0)
	{
		buf[buf_len] = '\0';
		if (!(backup[fd]))
			backup[fd] = ft_strdup1(buf);
		else
			backup[fd] = ft_strjoin1(backup[fd], buf);
		find_index = find_index_function(backup[fd]);
		if (find_index >= 0)
			return (make_one_str(&backup[fd], line, find_index));
		buf_len = read(fd, buf, BUFFER_SIZE);
	}
	return (find_next_line(buf_len, &backup[fd], line));
}
