#include "../cub3d.h"

void	put_num(int *g_dirx, int *g_diry)
{
	g_dirx[0] = -1;
	g_dirx[1] = 0;
	g_dirx[2] = 1;
	g_dirx[3] = 0;
	g_dirx[4] = -1;
	g_dirx[5] = -1;
	g_dirx[6] = 1;
	g_dirx[7] = 1;
	g_diry[0] = 0;
	g_diry[1] = 1;
	g_diry[2] = 0;
	g_diry[3] = -1;
	g_diry[4] = -1;
	g_diry[5] = 1;
	g_diry[6] = 1;
	g_diry[7] = -1;
}

int	map_checker2(t_info *info, char **test_map)
{
	if (info->is_zero == 0)
	{
		write(1, "No place\n", 9);
		return (0);
	}
	if (info->player_num != 1)
	{
		printf("player num error (%d)\n", info->player_num);
		return (0);
	}
	if (info->p == 0)
	{
		printf("player out\n");
		return (0);
	}
	write(1, "Map check : OK\n", 15);
	free_map(test_map, 103);
	return (1);
}

void	init_put_num(t_info *info)
{
	info->is_zero = 0;
	info->p = 0;
}
