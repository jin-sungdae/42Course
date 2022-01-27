/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonchoi <seonchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 20:15:02 by seonchoi          #+#    #+#             */
/*   Updated: 2021/07/02 17:59:51 by seonchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	memory_plus(t_info *info)
{
	int	i[2];

	i[0] = 0;
	info->texture = (int **)malloc(sizeof(int *) * 11);
	if (!info->texture)
		return (-1);
	while (i[0] < 11)
	{
		info->texture[i[0]] = (int *)malloc(sizeof(int) * (TEX_H * TEX_W));
		if (!info->texture[i[0]])
			return (-1);
		i[0]++;
	}
	i[0] = 0;
	while (i[0] < 11)
	{
		i[1] = 0;
		while (i[1] < TEX_H * TEX_W)
		{
			info->texture[i[0]][i[1]] = 0;
			i[1]++;
		}
		i[0]++;
	}
	return (0);
}

int	memory_plus2(t_info *info)
{
	info->m_x2 = 0;
	info->path = (char **)malloc(sizeof(char *) * 4);
	if (!info->path)
		return (-1);
	while (info->m_x2 < 4)
	{
		info->path[info->m_x2] = (char *)malloc(sizeof(char) * (TEX_H * TEX_W));
		if (!info->path[info->m_x2])
			return (-1);
		info->m_x2++;
	}
	info->m_x2 = 0;
	while (info->m_x2 < 4)
	{
		info->m_y2 = 0;
		while (info->m_y2 < TEX_H * TEX_W)
		{
			info->path[info->m_x2][info->m_y2] = 0;
			info->m_y2++;
		}
		info->m_x2++;
	}
	free_path(info);
	return (0);
}

void	initialization(t_info *info)
{
	info->key.key_a = 0;
	info->key.key_w = 0;
	info->key.key_s = 0;
	info->key.key_d = 0;
	info->key.key_left = 0;
	info->key.key_right = 0;
	info->key.key_esc = 0;
	info->movespeed = 0.05;
	info->rotspeed = 0.05;
	info->zbuffer = (double *)malloc(sizeof(double) * WIDTH);
	info->buf = (int **)malloc(sizeof(int *) * HEIGHT);
}

void	first_info(t_info *info)
{
	int	i;
	int	j;

	initialization(info);
	i = 0;
	while (i < HEIGHT)
	{
		info->buf[i] = (int *)malloc(sizeof(int) * (HEIGHT));
		i++;
	}
	i = 0;
	while (i < HEIGHT)
	{
		j = 0;
		while (j < WIDTH)
		{
			info->buf[i][j] = 0;
			j++;
		}
		i++;
	}
}

void	clean_img(t_img *img)
{
	img->img = 0;
	img->data = 0;
	img->img_height = 0;
	img->bpp = 0;
	img->size_l = 0;
	img->endian = 0;
	img->img_width = 0;
}
