/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjin <sjin@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 22:39:31 by sjin              #+#    #+#             */
/*   Updated: 2021/07/05 22:39:33 by sjin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	put_num(int *g_dirx, int *g_diry)
{
	g_dirx[0] = -1;
	g_dirx[1] = 0;
	g_dirx[2] = 1;
	g_dirx[3] = 0;
	g_dirx[4] = -1;
	g_dirx[5] = -1;
	g_dirx[6] = 1;
	g_dirx[7] = 1;
	g_diry[0] = 0;
	g_diry[1] = 1;
	g_diry[2] = 0;
	g_diry[3] = -1;
	g_diry[4] = -1;
	g_diry[5] = 1;
	g_diry[6] = 1;
	g_diry[7] = -1;
}

int	map_checker2(t_info *info, char **test_map)
{
	if (info->is_zero == 0)
	{
		write(1, "Error\n", 7);
		write(1, "player_zero\n", 14);
		return (0);
	}
	if (info->player->player_num != 1)
	{
		write(1, "Error\n", 7);
		write(1, "Too_many_player Error\n", 23);
		return (0);
	}
	if (info->p == 0)
	{
		write(1, "Error\n", 7);
		write(1, "Not play Error\n", 16);
		return (0);
	}
	free_map(test_map, 103);
	return (1);
}

void	init_put_num(t_info *info)
{
	info->is_zero = 0;
	info->p = 0;
}
