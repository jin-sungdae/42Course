/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjin <sjin@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 22:33:57 by sjin              #+#    #+#             */
/*   Updated: 2021/07/05 22:34:05 by sjin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	loop(t_info *info)
{
	mlx_put_image_to_window(info->var->mlx,
		info->var->win, info->img->img, 0, 0);
	ft_draw(info);
	ft_player_draw(info);
	ft_element(info);
	return (0);
}

void	main_loop(t_info *info)
{
	mlx_loop_hook(info->var->mlx, loop, info);
	mlx_hook(info->var->win, 2, 1L << 0, key_hook, info);
	mlx_hook(info->var->win, 33, 1L << 5, close_clean, info);
    mlx_hook(info->var->win, 17, 0, &cub_exit, 0);
	mlx_loop(info->var->mlx);
}

int	mlx_initial(t_info *info)
{
	info->var->mlx = mlx_init();
	info->frame = 0;
	info->var->win = mlx_new_window(info->var->mlx,
			info->map->line_len * 64,
			info->map->index * 64, "so_Long");
	info->img->img = mlx_new_image(info->var->mlx, info->map->line_len * 64,
			info->map->index * 64);
	info->img->addr = mlx_get_data_addr(info->img->img, &info->img->bpp,
			&info->img->line_l, &info->img->endian);
	init_player_image(info);
	init_floor_image(info);
	init_wall_image(info);
	init_exit_image(info);
	init_collection_image(info);
	main_loop(info);
	display_moves(info);
	return (1);
}

int	check_mapline(t_info *info, char **map)
{
	int	i;
	int	len;

	i = 0;
	while (i < info->map->index)
	{
		len = ft_strlen(map[i]);
		if (info->map->line_len != len)
		{
			write(1, "Error\n", 6);
			write(1, "plz check map line\n", 20);
			return (0);
		}
		i++;
	}
	return (1);
}

int	main(int argc, char *argv[])
{
	t_info	*info;

	if (argc == 2)
	{
		info = init_memory();
		if (!treat_description(argv[1], info))
			return (0);
		split_map(info);
		if (!(check_mapline(info, info->mapver)))
			return (0);
		if (!(map_checker(info)))
			return (0);
		check_elements(info);
		main_errors(info);
		mlx_initial(info);
		if (info)
			free_memory(info);
	}
	return (0);
}
