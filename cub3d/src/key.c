#include "../cub3d.h"

int	key_press(int key, t_info *info)
{
	if (key == K_ESC)
		exit(0);
	else if (key == K_W)
		info->key.key_w = 1;
	else if (key == K_A)
		info->key.key_a = 1;
	else if (key == K_S)
		info->key.key_s = 1;
	else if (key == K_D)
		info->key.key_d = 1;
	else if (key == K_AR_L)
		info->key.key_left = 1;
	else if (key == K_AR_R)
		info->key.key_right = 1;
	return (0);
}

int	key_release(int key, t_info *info)
{
	if (key == K_ESC)
		exit(0);
	else if (key == K_W)
		info->key.key_w = 0;
	else if (key == K_A)
		info->key.key_a = 0;
	else if (key == K_S)
		info->key.key_s = 0;
	else if (key == K_D)
		info->key.key_d = 0;
	else if (key == K_AR_L)
		info->key.key_left = 0;
	else if (key == K_AR_R)
		info->key.key_right = 0;
	return (0);
}

void	key_update(t_info *info)
{
	if (info->key.key_w)
		rudder_up_key(info);
	if (info->key.key_s)
		rudder_down_key(info);
	if (info->key.key_a)
		rudder_left_key(info);
	if (info->key.key_d)
		rudder_right_key(info);
	if (info->key.key_left)
		camera_left(info);
	if (info->key.key_right)
		camera_right(info);
	if (info->key.key_esc)
		exit(0);
}

void	camera_left(t_info *info)
{
	double	olddir_x;
	double	oldplane_x;

	olddir_x = info->dir_x;
	oldplane_x = info->plane_x;
	info->dir_x = info->dir_x * cos(info->rotspeed)
		- info->dir_y * sin(info->rotspeed);
	info->dir_y = olddir_x * sin(info->rotspeed)
		+ info->dir_y * cos(info->rotspeed);
	info->plane_x = info->plane_x * cos(info->rotspeed)
		- info->plane_y * sin(info->rotspeed);
	info->plane_y = oldplane_x * sin(info->rotspeed)
		+ info->plane_y * cos(info->rotspeed);
}

void	camera_right(t_info *info)
{
	double	olddir_x;
	double	oldplane_x;

	olddir_x = info->dir_x;
	oldplane_x = info->plane_x;
	info->dir_x = info->dir_x * cos(-info->rotspeed)
		- info->dir_y * sin(-info->rotspeed);
	info->dir_y = olddir_x * sin(-info->rotspeed)
		+ info->dir_y * cos(-info->rotspeed);
	info->plane_x = info->plane_x * cos(-info->rotspeed)
		- info->plane_y * sin(-info->rotspeed);
	info->plane_y = oldplane_x * sin(-info->rotspeed)
		+ info->plane_y * cos(-info->rotspeed);
}
