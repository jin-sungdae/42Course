/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_second.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjin <sjin@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 22:39:08 by sjin              #+#    #+#             */
/*   Updated: 2021/07/05 22:39:09 by sjin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	init_var(t_info *info)
{
	info->var->win = NULL;
	info->var->mlx = NULL;
}

void	init_key(t_info *info)
{
	info->key.up = 0;
	info->key.down = 0;
	info->key.left = 0;
	info->key.right = 0;
}

void	info_init(t_info *info)
{
	info->floor = NULL;
	info->bottom = NULL;
	info->mapver = NULL;
	info->moves = 0;
	info->frame = 0;
	info->c_num = 0;
	info->e_num = 0;
}

t_info	*init_memory(void)
{
	t_info	*info;

	info = (t_info *)malloc(sizeof(t_info));
	info->player = (t_player *)malloc(sizeof(t_info));
	init_player(info);
	info->collection_list = (t_collection_list *)malloc
		(sizeof(t_collection_list));
	init_collection_list(info->collection_list);
	info->exit_list = (t_exit_list *)malloc(sizeof(t_exit_list));
	init_exit_list(info->exit_list);
	info->img = (t_img *)malloc(sizeof(t_img));
	init_img(info);
	info->map = (t_map *)malloc(sizeof(t_map));
	init_map1(info);
	info->var = (t_var *)malloc(sizeof(t_var));
	init_var(info);
	init_key(info);
	info_init(info);
	info->tmp = (char *)malloc(sizeof(char) * 1);
	info->tmp[0] = 'a';
	info->tmp[1] = '\0';
	if (!info || !info->player || !info->collection_list
		|| !info->exit_list || !info->img || !info->map || !info->var)
		free_memory(info);
	return (info);
}
