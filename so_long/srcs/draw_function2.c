/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_function2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjin <sjin@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 22:36:45 by sjin              #+#    #+#             */
/*   Updated: 2021/07/05 22:36:46 by sjin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	draw_on_img(t_img *img, t_img *img2, int x, int y)
{
	t_draw	draw;

	draw.x = 0;
	while (draw.x < 64)
	{
		draw.y = 0;
		while (draw.y < 64)
		{
			draw.r_x = (float)draw.x / (float)64;
			draw.r_y = (float)draw.y / (float)64;
			draw.pos_x = draw.r_x * img2->width;
			draw.pos_y = draw.r_y * img2->height;
			draw.color = get_pixel(img2, draw.pos_x, draw.pos_y);
			draw.p_data_x = x + draw.x;
			draw.p_data_y = y + draw.y;
			if (draw.color != (int)0xFF000000)
				set_pixel(img, draw.p_data_x, draw.p_data_y, draw.color);
			draw.y++;
		}
		draw.x++;
	}
}

void	ft_player_draw(t_info *info)
{
	info->player->smooth_x = info->player->pos_x;
	info->player->smooth_y = info->player->pos_y;
	draw_on_img(info->img, &(info->player->img),
		(int)info->player->smooth_x * 64, (int)info->player->smooth_y * 64);
}

void	ft_draw(t_info *info)
{
	int	i;
	int	j;

	i = 0;
	while (info->mapver[i])
	{
		j = 0;
		while (info->mapver[i][j])
		{
			if (info->mapver[i][j] == '1')
				draw_on_img(info->img, info->floor, j * 64, i * 64);
			else
				draw_on_img(info->img, info->bottom, j * 64, i * 64);
			j++;
		}
		i++;
	}
}
