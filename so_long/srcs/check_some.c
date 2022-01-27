/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_some.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjin <sjin@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 22:36:27 by sjin              #+#    #+#             */
/*   Updated: 2021/07/05 22:36:30 by sjin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	check_elements(t_info *info)
{
	int		i;
	int		j;

	i = 0;
	init_collection_list(info->collection_list);
	init_exit_list(info->exit_list);
	init_player(info);
	while (i < info->map->index)
	{
		j = 0;
		while (j < info->map->line_len)
		{
			is_collectible_char(info, info->mapver, i, j);
			is_exit_char(info, info->mapver, i, j);
			is_player_char(info, info->mapver, i, j);
			j++;
		}
		i++;
	}
}

int	cub_exit(void)
{
	exit(0);
	return (0);
}
