/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_check_move_check.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjin <sjin@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 22:37:34 by sjin              #+#    #+#             */
/*   Updated: 2021/07/05 22:37:38 by sjin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	is_collectible(t_info *info, int i, int j)
{
	t_collection	*collect;

	collect = info->collection_list->first;
	while (collect)
	{
		if (collect->pos_y == j && collect->pos_x == i)
			return (1);
		collect = collect->next;
	}
	return (0);
}

void	set_to_true(t_info *info)
{
	t_collection	*collect;

	collect = info->collection_list->first;
	while (collect)
	{
		if (collect->pos_y == (int)info->player->pos_x
			&& (int)collect->pos_x == info->player->pos_y)
		{
			collect->collection_num = 0;
			return ;
		}
		collect = collect->next;
	}
}

int	is_exit(t_info *info, int i, int j)
{
	t_exit	*exit;

	exit = info->exit_list->first;
	while (exit)
	{
		if (exit->pos_x == i && exit->pos_y == j)
			return (1);
		exit = exit->next;
	}
	return (0);
}

int	c_list_length(t_collection_list *list)
{
	int					length;
	t_collection		*collect;

	if (!list)
		return (0);
	length = 0;
	collect = list->first;
	while (collect)
	{
		length++;
		collect = collect->next;
	}
	return (length);
}

int	c_all_touched(t_info *info)
{
	t_collection		*collect;
	int					length;
	int					count;

	count = 0;
	length = c_list_length(info->collection_list);
	collect = info->collection_list->first;
	while (collect)
	{
		if (collect->collection_num != 1)
			count++;
		collect = collect->next;
	}
	if (count == length)
		return (1);
	return (0);
}
