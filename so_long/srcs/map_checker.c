/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjin <sjin@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 22:38:11 by sjin              #+#    #+#             */
/*   Updated: 2021/07/05 22:38:13 by sjin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	check_map(char **map, int x, int y, int *p)
{
	int		i;
	int		g_dirx[8];
	int		g_diry[8];

	put_num(g_dirx, g_diry);
	if (map[y][x] == '1' || map[y][x] == 'x')
		return (1);
	if (map[y][x] == 'P')
		*p = 1;
	if (map[y][x] == ' ')
		return (0);
	map[y][x] = 'x';
	i = -1;
	while (++i < 8)
		if (check_map(map, x + g_dirx[i], y + g_diry[i], p) == 0)
			return (0);
	return (1);
}

char	**init_map(char **map, t_info *info)
{
	char	**testmap;

	testmap = (char **)malloc(sizeof(char *) * 103);
	if (!testmap)
		return (0);
	testmap[102] = 0;
	info->m_y = -1;
	while (++info->m_y < 102)
	{
		testmap[info->m_y] = (char *)malloc(sizeof(char) * 103);
		if (!testmap[info->m_y])
			return (0);
		testmap[info->m_y][102] = 0;
		info->m_x = -1;
		while (++info->m_x < 102)
			testmap[info->m_y][info->m_x] = ' ';
	}
	info->m_y = -1;
	while (map[++info->m_y])
	{
		info->m_x = -1;
		while (map[info->m_y][++info->m_x])
			testmap[info->m_y + 1][info->m_x + 1] = map[info->m_y][info->m_x];
	}
	return (testmap);
}

int	free_map(char **map, int cnt)
{
	while (cnt >= 0)
	{
		free(map[cnt]);
		cnt--;
	}
	free(map);
	return (0);
}

int	map_checker(t_info *info)
{
	char	**testmap;

	testmap = init_map(info->mapver, info);
	init_put_num(info);
	info->m_y1 = -1;
	while (testmap[++info->m_y1])
	{
		info->m_x1 = -1;
		while (testmap[info->m_y1][++info->m_x1])
		{
			if (testmap[info->m_y1][info->m_x1] == '0')
			{
				info->is_zero = 1;
				if (check_map(testmap, info->m_x1, info->m_y1, &info->p) == 0)
				{
					write(1, "Error\n map Error checkplease", 29);
					free_map(testmap, 103);
					return (0);
				}
			}
		}
	}
	if (!map_checker2(info, testmap))
		return (0);
	return (1);
}
