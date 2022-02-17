#include "../cub3d.h"

void	free_path(t_info *info)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		free(info->path[i]);
		i++;
	}
}
