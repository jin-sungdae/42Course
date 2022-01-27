/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   some_function.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjin <sjin@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 22:38:40 by sjin              #+#    #+#             */
/*   Updated: 2021/07/05 22:38:41 by sjin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	main_errors(t_info *info)
{
	if (!(info->collection_list->first) || !(info->exit_list->first))
	{
		write(1, "error\n", 6);
        write(1, "collect or exit is error\n", 26);
		free_memory(info);
	}
}

t_collection	*get_collectible(t_info *info, int i, int j)
{
	t_collection	*collect;

	collect = info->collection_list->first;
	while (collect)
	{
		if (collect->pos_x == i && collect->pos_y == j)
			return (collect);
		collect = collect->next;
	}
	return (NULL);
}

void	ft_element_sub(t_info *info, t_collection *collect, int i, int j)
{
	if (info->mapver[i][j] == 'C')
	{
		collect = get_collectible(info, i, j);
		if (collect && collect->collection_num == 1)
			draw_on_img(info->img, &(info->collection_list->img),
				j * 64, i * 64);
	}
	else if (info->mapver[i][j] == 'E')
		draw_on_img(info->img, &(info->exit_list->img),
			j * 64, i * 64);
}

void	ft_element(t_info *info)
{
	t_v				v;
	t_collection	*collect;

	collect = NULL;
	v.i = 0;
	v.y = 1;
	while (info->mapver[v.i])
	{
		v.x = 1;
		v.j = 0;
		while (info->mapver[v.i][v.j])
		{
			ft_element_sub(info, collect, v.i, v.j);
			v.x += 64;
			v.j++;
		}
		v.y += 64;
		v.i++;
	}
}
