/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjin <sjin@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 22:38:59 by sjin              #+#    #+#             */
/*   Updated: 2021/07/05 22:39:03 by sjin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	free_map1(t_info *info)
{
	int	i;

	if (!info->map)
		return ;
	i = info->map->index;
	if (i < 0)
	{
		write(1, "ERROR", 5);
        write(1, "map free error\n", 16);
		return ;
	}
	while (i >= 0)
	{
		if (info->mapver[i])
		{
			free(info->mapver[i]);
		}
		i--;
	}
}

void	free_img(t_info *info)
{
	if (info->img)
		free(info->img);
}

void	free_exit_list(t_exit_list *list)
{
	t_exit	*exit;
	t_exit	*next;

	exit = list->first;
	while (exit)
	{
		next = exit->next;
		free(exit);
		exit = next;
	}
	free(list);
}

void	free_collection_list(t_collection_list *list)
{
	t_collection	*collection;
	t_collection	*next;

	collection = list->first;
	while (collection)
	{
		next = collection->next;
		free(collection);
		collection = next;
	}
	free(list);
}

void	free_memory(t_info *info)
{
	if (!info)
		exit (0);
	if (info->img)
		free_img(info);
	if (info->mapver)
		free_map1(info);
	if (info->tmp)
		free(info->tmp);
	if (info->exit_list)
		free_exit_list(info->exit_list);
	if (info->collection_list)
		free_collection_list(info->collection_list);
	if (info->var)
		free(info->var);
	if (info->player)
		free(info->player);
	if (info->floor)
		free(info->floor);
	if (info->bottom)
		free(info->bottom);
	if (info)
		free(info);
	exit (1);
}
