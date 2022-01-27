/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonchoi <seonchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 21:18:14 by seonchoi          #+#    #+#             */
/*   Updated: 2021/07/01 21:18:36 by seonchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	rudder_up_key(t_info *info)
{
	if (info->map[(int)(info->pos_x + info->dir_x
			* info->movespeed)][(int)(info->pos_y)] != '1')
		info->pos_x += info->dir_x * info->movespeed;
	if (info->map[(int)(info->pos_x)][(int)(info->pos_y
			+ info->dir_y * info->movespeed)] != '1')
		info->pos_y += info->dir_y * info->movespeed;
}

void	rudder_down_key(t_info *info)
{
	if (info->map[(int)(info->pos_x - info->dir_x
			* info->movespeed)][(int)(info->pos_y)] != '1')
		info->pos_x -= info->dir_x * info->movespeed;
	if (info->map[(int)(info->pos_x)][(int)(info->pos_y
			- info->dir_y * info->movespeed)] != '1')
		info->pos_y -= info->dir_y * info->movespeed;
}

void	rudder_left_key(t_info *info)
{
	if (info->map[(int)(info->pos_x - info->plane_x
			* info->movespeed)][(int)(info->pos_y)] != '1')
		info->pos_x -= info->plane_x * info->movespeed;
	if (info->map[(int)(info->pos_x)][(int)(info->pos_y
			- info->plane_y * info->movespeed)] != '1')
		info->pos_y -= info->plane_y * info->movespeed;
}

void	rudder_right_key(t_info *info)
{
	if (info->map[(int)(info->pos_x + info->plane_x
			* info->movespeed)][(int)(info->pos_y)] != '1')
		info->pos_x += info->plane_x * info->movespeed;
	if (info->map[(int)(info->pos_x)][(int)(info->pos_y
			+ info->plane_y * info->movespeed)] != '1')
		info->pos_y += info->plane_y * info->movespeed;
}
