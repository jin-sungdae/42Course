#include "../cub3d.h"

void	floar_casting(t_info *info)
{
	int	y;
	int	x;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			if (y < HEIGHT / 2 + 1)
				info->buf[y][x] = info->ceiling_color;
			if (y > HEIGHT / 2 + 1)
				info->buf[y][x] = info->floor_color;
			x++;
		}
		y++;
	}
}
