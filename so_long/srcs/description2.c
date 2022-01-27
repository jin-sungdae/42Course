/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   description2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjin <sjin@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 22:36:35 by sjin              #+#    #+#             */
/*   Updated: 2021/07/05 22:36:37 by sjin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	find_player_pos(char a)
{
	if (a == 'P')
		return (1);
	return (0);
}

int	file_name_check(char *filename)
{
	int	i;

	i = ft_strlen1(filename) - 1;
	if (!filename || !(filename[i] == 'r' && filename[i - 1] == 'e'
			&& filename[i - 2] == 'b' && filename[i - 3] == '.'))
	{
		write(1, "Error\n", 7);
        write(1, "file_name_check_error\n", 23);
		return (0);
	}
	if (filename[i] == 'r' && filename[i - 1] == 'e' && filename[i - 2]
		== 'b' && filename[i - 3] == '.')
		return (1);
	return (0);
}

int	file_exists(char *file_name)
{
	int	fd;
	int	len;

	len = ft_strlen1(file_name);
	if (!file_name || len == 0)
		return (-1);
	fd = open(file_name, O_RDONLY);
	if (fd == -1)
	{
		close(fd);
		return (-1);
	}
	if (!(file_name[len - 4] == '.' && file_name[len - 3] == 'x'
			&& file_name[len - 2] == 'p' && file_name[len - 1] == 'm'))
		return (-1);
	return (1);
}

int	is_space(char c)
{
	if ((c >= 9 && c <= 13) || c == 32)
		return (1);
	else
		return (0);
}

int	is_map_character(char c)
{
	if (c == '0' || c == '1' || c == 'P' || c == 'E' || c == 'C')
		return (1);
	return (0);
}
