/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   description.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjin <sjin@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 22:38:47 by sjin              #+#    #+#             */
/*   Updated: 2021/07/05 22:38:48 by sjin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	treat_description(char *file_name, t_info *info)
{
	char	*line;
	int		fd;
	int		gnl_return;

	if (!file_name_check(file_name))
		return (0);
	fd = open(file_name, O_RDONLY);
	if (!fd)
		return (-1);
	gnl_return = get_next_line(fd, &line);
	info->map->line_len = ft_strlen(line);
	while (gnl_return == 1)
	{
		if (!parse_line(line, info))
		{
			free(line);
			return (0);
		}
		free(line);
		gnl_return = get_next_line(fd, &line);
	}
	parse_line(line, info);
	free(line);
	close(fd);
	return (1);
}

int	parse_line(char *line, t_info *info)
{
	int		i;
	int		num;

	num = 0;
	i = 0;
	while (line[i] != '\0')
	{
		if (is_space(line[i]))
		{
			i++;
			num++;
		}
		else if (is_map_character(line[i]))
			i = i + save_map1(line, info) - num;
		else
			return (0);
	}
	return (1);
}
