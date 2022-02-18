#include "../cub3d.h"

int	find_player_pos(char a)
{
	if (a == 'N' || a == 'S' || a == 'W' || a == 'E')
		return (1);
	return (0);
}

int	file_name_check(char *filename)
{
	int	i;

	i = ft_strlen1(filename) - 1;
	if (!filename || !(filename[i] == 'b' && filename[i - 1] == 'u'
			&& filename[i - 2] == 'c' && filename[i - 3] == '.'))
	{
		printf("file_name : ERROR\n");
		return (0);
	}
	return (1);
}

int	file_exists(char *file_name)
{
	int	fd;
	int	len;

	len = ft_strlen1(file_name);
	if (!file_name || len == 0)
		return (0);
	fd = open(file_name, O_RDONLY);
	if (fd == -1)
	{
		close(fd);
		return (0);
	}
	if (!(file_name[len - 4] == '.' && file_name[len - 3] == 'x'
			&& file_name[len - 2] == 'p' && file_name[len - 1] == 'm'))
		return (0);
	return (1);
}

int	is_space(char c)
{
	if ((c >= 9 && c <= 13) || c == 32)
		return (1);
	else
		return (0);
}

int	is_map_character(char c)
{
	if (c == '0' || c == '1' || c == 'W' || c == 'S' || c == 'E' || c == 'N')
		return (1);
	return (0);
}
