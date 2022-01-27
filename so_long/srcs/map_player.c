/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_player.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjin <sjin@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 22:38:20 by sjin              #+#    #+#             */
/*   Updated: 2021/07/05 22:38:22 by sjin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	save_map1(char *line, t_info *info)
{
	int			line_len;
	int			j;
	static int	i;

	line_len = ft_strlen(line);
	info->map->index = i;
	i++;
	j = 0;
	while (j < line_len)
	{
		if (find_player_pos(line[j]))
		{
			info->player->player_num++;
			check_player(info, j);
		}
		j++;
	}
	info->tmp = ft_strjoin1(info->tmp, line);
	info->tmp = ft_strjoin1(info->tmp, "a");
	return (line_len);
}

void	check_player(t_info *info, int pos_x)
{
	info->player->pos_x = pos_x;
	info->player->pos_y = info->map->index;
}

void	split_map(t_info *info)
{
	info->mapver = ft_split(info->tmp, 'a');
	info->map->index++;
}
