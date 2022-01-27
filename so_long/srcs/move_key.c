/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_key.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjin <sjin@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 22:39:39 by sjin              #+#    #+#             */
/*   Updated: 2021/07/05 22:39:40 by sjin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	other_keys(int key, t_info *info)
{
	if (info->mapver[(int)(info->player->pos_y)][(int)(info->player->pos_x + 1)]
		!= '1' && key == K_D)
	{
		info->player->pos_x += 1;
		info->moves++;
		display_moves(info);
	}
	if (key == K_ESC)
		close_clean(info);
	if (is_collectible(info, (int)info->player->pos_y,
			(int)info->player->pos_x) == 1)
		set_to_true(info);
	if ((is_exit(info, (int)info->player->pos_y,
				(int)info->player->pos_x) == 1)
		&& c_all_touched(info) == 1)
		close_clean(info);
}

int	key_hook(int key, t_info *info)
{
	if (info->mapver[(int)(info->player->pos_y - 1)][(int)(info->player->pos_x)]
		!= '1' && key == K_W)
	{
		info->player->pos_y -= 1;
		info->moves++;
		display_moves(info);
	}
	else if (info->mapver[(int)(info->player->pos_y)]
	[(int)(info->player->pos_x - 1)] != '1' && key == K_A)
	{
		info->player->pos_x -= 1;
		info->moves++;
		display_moves(info);
	}
	else if (info->mapver[(int)(info->player->pos_y + 1)]
		[(int)(info->player->pos_x)]
		!= '1' && key == K_S)
	{
		info->player->pos_y += 1;
		info->moves++;
		display_moves(info);
	}
	other_keys(key, info);
	return (1);
}

int	close_clean(t_info *info)
{
	if (info->player->img.img)
		mlx_destroy_image(info->var->mlx, info->player->img.img);
	if (info->exit_list->img.img)
		mlx_destroy_image(info->var->mlx, info->exit_list->img.img);
	if (info->collection_list->img.img)
		mlx_destroy_image(info->var->mlx, info->collection_list->img.img);
	if (info->bottom->img)
		mlx_destroy_image(info->var->mlx, info->bottom->img);
	if (info->floor->img)
		mlx_destroy_image(info->var->mlx, info->floor->img);
	if (info->img->img)
		mlx_destroy_image(info->var->mlx, info->img->img);
	if (info->var->win)
		mlx_destroy_window(info->var->mlx, info->var->win);
	if (info->var->mlx)
		free(info->var->mlx);
	free_memory(info);
	exit (0);
}
