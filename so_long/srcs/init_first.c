/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_first.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjin <sjin@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 22:36:52 by sjin              #+#    #+#             */
/*   Updated: 2021/07/05 22:36:53 by sjin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	init_player(t_info *info)
{
	info->player->pos_x = 0;
	info->player->pos_y = 0;
	info->player->smooth_x = 0;
	info->player->smooth_y = 0;
	info->player->player_num = 0;
}

void	init_collection_list(t_collection_list *list)
{
	list->first = NULL;
	list->is_empty = 1;
}

void	init_exit_list(t_exit_list *list)
{
	list->first = NULL;
	list->is_empty = 1;
}

void	init_img(t_info *info)
{
	info->img->img = NULL;
	info->img->addr = NULL;
	info->img->bpp = 0;
	info->img->line_l = 0;
	info->img->endian = 0;
	info->img->width = 0;
	info->img->height = 0;
}

void	init_map1(t_info *info)
{
	info->map->index = 0;
	info->map->line_len = 0;
	info->map->index_max = 0;
}
