#ifndef CUB3D_H
# define CUB3D_H

# include "mlx.h"
# include <math.h>
# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include "./get_next_line/get_next_line.h"
# define X_EVENT_KEY_PRESS	2
# define X_EVENT_KEY_RELEASE 3
# define X_EVENT_KEY_EXIT	17
# define TEX_W 64
# define TEX_H 64
# define HEIGHT 1000
# define WIDTH 1000
# define K_W 13
# define K_S 1
# define K_A 0
# define K_D 2
# define K_AR_L 123
# define K_AR_R 124
# define K_ESC 53

typedef struct s_color
{
	int	i;
	int	r;
	int	g;
	int	b;
	int	color;
}				t_color;

typedef struct s_img
{
	void	*img;
	int		*data;
	int		size_l;
	int		bpp;
	int		endian;
	int		img_width;
	int		img_height;
}				t_img;

typedef struct s_key
{
	int	key_w;
	int	key_s;
	int	key_a;
	int	key_d;
	int	key_left;
	int	key_right;
	int	key_esc;
}				t_key;

typedef struct s_info
{
	void	*mlx;
	void	*win;
	char	*tmp;
	char	**map;
	char	**path;
	int		**texture;
	int		**buf;
	int		floor_color;
	int		ceiling_color;
	int		index;
	int		check_player_point;
	int		player_num;
	int		is_zero;
	int		p;
	int		m_x;
	int		m_y;
	int		m_x1;
	int		m_y1;
	int		map_width;
	int		map_height;
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
	double	*zbuffer;
	double	movespeed;
	double	rotspeed;
	t_key	key;
	t_img	img;
}				t_info;

typedef struct s_calac_data
{
	int		map_x;
	int		map_y;
	int		step_x;
	int		step_y;
	int		hit;
	int		side;
	int		lineheight;
	int		drawstart;
	int		drawend;
	int		texnum;
	int		tex_x;
	int		tex_y;
	int		color;
	int		index_y;
	double	wall_x;
	double	step;
	double	texPos;
	double	camera_x;
	double	raydir_x;
	double	raydir_y;
	double	deltadist_x;
	double	deltadist_y;
	double	sidedist_x;
	double	sidedist_y;
	double	perpwalldist;
}				t_calac_data;

void	load_image(t_info *info, int *texture, char *path, t_img *img);
void	load_texture(t_info *info);
void	first_info(t_info *info);
void	split_map(t_info *info);
void	key_update(t_info *info);
void	calc(t_info *info);
void	draw(t_info *info);
void	floar_casting(t_info *info);
void	calc_color(t_info *info, t_calac_data *d, int x);
void	check_player(t_info *info, char player_pos, int pos_x);
void	ray_plus(t_calac_data *data, t_info *info);
void	textured_input(t_calac_data *data, t_info *info);
void	hit_check(t_calac_data *data, t_info *info);
void	put_rgb(char location, t_info *info, int color);
void	camera_left(t_info *info);
void	camera_right(t_info *info);
void	rudder_up_key(t_info *info);
void	rudder_down_key(t_info *info);
void	rudder_left_key(t_info *info);
void	rudder_right_key(t_info *info);
void	clean_img(t_img *img);
void	input_player_n_s(t_info *info, char player_pos);
void	input_player_w_e(t_info *info, char player_pos);
int		main_loop(t_info *info);
int		key_press(int key, t_info *info);
int		key_release(int key, t_info *info);
int		memory_plus(t_info *info);
int		memory_plus2(t_info *info);
int		find_player_pos(char a);
int		file_name_check(char *filename);
int		file_exists(char *file_name);
int		is_space(char c);
int		is_map_character(char c);
int		save_map1(char *line, t_info *info);
int		config_color(char location, char *line, t_info *info);
int		config_path(int index, char *line, t_info *info);
int		is_type_identifier(char a, char b, char *line, t_info *info);
int		parse_line(char *line, t_info *info);
int		treat_description(char *file_name, t_info *info);
int		main(int argc, char *argv[]);
int		ft_isdigit(int c);
char	*ft_strdup(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlcpy(char *dest, const char *src, size_t num);
int		ft_strlen(char *str);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	**ft_split(char const *s, char c);
void	init_put_num(t_info *info);
void	put_num(int *g_dirx, int *g_diry);
char	**init_map(char **map, t_info *info);
int		check_map(char **map, int x, int y, int *p);
int		free_map(char **map, int cnt);
int		map_checker(t_info *info);
int		map_checker2(t_info *info, char **test_map);
int		ft_max(int a, int b);

#endif
