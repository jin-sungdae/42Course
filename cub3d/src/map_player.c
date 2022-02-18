#include "../cub3d.h"

int	save_map1(char *line, t_info *info)
{
	int			line_len;
	int			j;
	static int	i;

	line_len = ft_strlen(line);
	info->index = i;
	i++;
	j = 0;
	while (j < line_len)
	{
		if (find_player_pos(line[j]))
		{
			info->player_num++;
			check_player(info, line[j], j);
		}
		j++;
	}
	info->tmp = ft_strjoin1(info->tmp, line);
	info->tmp = ft_strjoin1(info->tmp, "a");
	info->map_width = ft_max(info->map_width, line_len);
	return (line_len);
}

void	check_player(t_info *info, char player_pos, int pos_x)
{
	info->pos_x = info->index + 0.5;
	info->pos_y = pos_x + 0.5;
	input_player_n_s(info, player_pos);
	input_player_w_e(info, player_pos);
}

void	split_map(t_info *info)
{
	info->map = ft_split(info->tmp, 'a');
	info->index++;
}

void	input_player_n_s(t_info *info, char player_pos)
{
	if (player_pos == 'N')
	{
		info->dir_x = -1.0;
		info->dir_y = 0.0;
		info->plane_x = 0.0;
		info->plane_y = 0.66;
	}
	if (player_pos == 'S')
	{
		info->dir_x = 1.0;
		info->dir_y = 0.0;
		info->plane_x = 0.0;
		info->plane_y = -0.66;
	}
}

void	input_player_w_e(t_info *info, char player_pos)
{
	if (player_pos == 'W')
	{
		info->dir_x = 0.0;
		info->dir_y = -1.0;
		info->plane_x = -0.66;
		info->plane_y = 0.0;
	}
	if (player_pos == 'E')
	{
		info->dir_x = 0.0;
		info->dir_y = 1.0;
		info->plane_x = 0.66;
		info->plane_y = 0.0;
	}
}
