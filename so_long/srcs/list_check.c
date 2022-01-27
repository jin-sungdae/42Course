/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjin <sjin@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 22:39:18 by sjin              #+#    #+#             */
/*   Updated: 2021/07/05 22:39:19 by sjin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	push_c_list(t_info *info, int x, int y)
{
	t_collection	*collect;
	t_collection	*temp;

	collect = (t_collection *)malloc(sizeof(t_collection));
	if (!collect)
		free_memory(info);
	collect->pos_x = x;
	collect->pos_y = y;
	collect->collection_num = 1;
	if (!info->collection_list->first)
	{
		collect->next = NULL;
		info->collection_list->first = collect;
		return ;
	}
	temp = info->collection_list->first;
	while (temp->next)
		temp = temp->next;
	temp->next = collect;
	collect->next = NULL;
}

void	push_e_list(t_info *info, int x, int y)
{
	t_exit	*exit;
	t_exit	*temp;

	exit = (t_exit *)malloc(sizeof(t_exit));
	if (!exit)
		free_memory(info);
	exit->pos_x = x;
	exit->pos_y = y;
	exit->exit_num = 1;
	if (!info->exit_list->first)
	{
		exit->next = NULL;
		info->exit_list->first = exit;
		return ;
	}
	temp = info->exit_list->first;
	while (temp->next)
		temp = temp->next;
	temp->next = exit;
	exit->next = NULL;
}

void	is_collectible_char(t_info *info, char **map, int i, int j)
{
	if (map[i][j] == 'C')
		push_c_list(info, i, j);
}

void	is_exit_char(t_info *info, char **map, int i, int j)
{
	if (map[i][j] == 'E')
		push_e_list(info, i, j);
}

void	is_player_char(t_info *info, char **map, int i, int j)
{
	if (map[i][j] == 'P')
	{
		info->player->pos_x = j;
		info->player->pos_y = i;
	}
}
