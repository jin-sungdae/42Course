#include "../cub3d.h"

void	calc(t_info *info)
{
	int				x;
	t_calac_data	data;

	x = 0;
	while (x < WIDTH)
	{
		data.camera_x = 2 * x / (double)WIDTH - 1;
		data.raydir_x = info->dir_x + info->plane_x * data.camera_x;
		data.raydir_y = info->dir_y + info->plane_y * data.camera_x;
		data.map_x = (int)info->pos_x;
		data.map_y = (int)info->pos_y;
		data.deltadist_x = fabs(1 / data.raydir_x);
		data.deltadist_y = fabs(1 / data.raydir_y);
		data.hit = 0;
		ray_plus(&data, info);
		hit_check(&data, info);
		textured_input(&data, info);
		calc_color(info, &data, x);
		x++;
	}
}

void	calc_color(t_info *info, t_calac_data *d, int x)
{
	if (d->side == 0 || d->side == 1)
		d->wall_x = info->pos_y + d->perpwalldist * d->raydir_y;
	else
		d->wall_x = info->pos_x + d->perpwalldist * d->raydir_x;
	d->wall_x -= floor(d->wall_x);
	d->tex_x = (int)(d->wall_x * (double)TEX_W);
	if (d->side == 0 && d->raydir_x > 0)
		d->tex_x = TEX_W - d->tex_x - 1;
	if (d->side == 1 && d->raydir_y < 0)
		d->tex_x = TEX_W - d->tex_x - 1;
	d->step = 1.0 * TEX_H / d->lineheight;
	d->texPos = (d->drawstart - HEIGHT / 2 + d->lineheight / 2) * d->step;
	d->index_y = d->drawstart;
	while (d->index_y < d->drawend)
	{
		d->tex_y = (int)d->texPos & (TEX_H - 1);
		d->texPos += d->step;
		d->color = info->texture[d->texnum][TEX_H * d->tex_y + d->tex_x];
		if (d->side == 0 || d->side == 1 || d->side == 2 || d->side == 3)
			d->color = info->texture[d->texnum][TEX_H * d->tex_y + d->tex_x];
		info->buf[d->index_y][x] = d->color;
		d->index_y++;
	}
	info->zbuffer[x] = d->perpwalldist;
}

void	hit_check(t_calac_data *data, t_info *info)
{
	while (data->hit == 0)
	{
		if (data->sidedist_x < data->sidedist_y)
		{
			data->sidedist_x += data->deltadist_x;
			data->map_x += data->step_x;
			if (data->step_x == 1)
				data->side = 0;
			else if (data->step_x == -1)
				data->side = 1;
		}
		else
		{
			data->sidedist_y += data->deltadist_y;
			data->map_y += data->step_y;
			if (data->step_y == 1)
				data->side = 2;
			else if (data->step_y == -1)
				data->side = 3;
		}
		if (info->map[data->map_x][data->map_y] == '1')
			data->hit = 1;
	}
}

void	textured_input(t_calac_data *data, t_info *info)
{
	if (data->side == 0 || data->side == 1)
		data->perpwalldist = (data->map_x - info->pos_x
				+ (1 - data->step_x) / 2) / data->raydir_x;
	else
		data->perpwalldist = (data->map_y - info->pos_y
				+ (1 - data->step_y) / 2) / data->raydir_y;
	data->lineheight = (int)(HEIGHT / data->perpwalldist);
	data->drawstart = -data->lineheight / 2 + HEIGHT / 2;
	if (data->drawstart < 0)
		data->drawstart = 0;
	data->drawend = data->lineheight / 2 + HEIGHT / 2;
	if (data->drawend >= HEIGHT)
		data->drawend = HEIGHT - 1;
	if (info->map[data->map_x][data->map_y] == '1' && data->side == 0)
		data->texnum = 0;
	else if (info->map[data->map_x][data->map_y] == '1' && data->side == 1)
		data->texnum = 1;
	else if (info->map[data->map_x][data->map_y] == '1' && data->side == 2)
		data->texnum = 2;
	else if (info->map[data->map_x][data->map_y] == '1' && data->side == 3)
		data->texnum = 3;
}

void	ray_plus(t_calac_data *data, t_info *info)
{
	if (data->raydir_x < 0)
	{
		data->step_x = -1;
		data->sidedist_x = (info->pos_x - data->map_x) * data->deltadist_x;
	}
	else
	{
		data->step_x = 1;
		data->sidedist_x = (data->map_x + 1.0 - info->pos_x)
			* data->deltadist_x;
	}
	if (data->raydir_y < 0)
	{
		data->step_y = -1;
		data->sidedist_y = (info->pos_y - data->map_y) * data->deltadist_y;
	}
	else
	{
		data->step_y = 1;
		data->sidedist_y = (data->map_y + 1.0 - info->pos_y)
			* data->deltadist_y;
	}
}
