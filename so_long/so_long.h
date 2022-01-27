/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjin <sjin@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 22:35:25 by sjin              #+#    #+#             */
/*   Updated: 2021/07/05 22:35:28 by sjin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "minilibx/mlx.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "./get_next_line/get_next_line.h"

# define X_EVENT_KEY_PRESS	2
# define X_EVENT_KEY_RELEASE 3
# define X_EVENT_KEY_EXIT	17
# define K_W 13
# define K_S 1
# define K_A 0
# define K_D 2
# define K_ESC 53

typedef struct s_key
{
	int	up;
	int	down;
	int	left;
	int	right;
	int	esc;
}				t_key;

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_l;
	int		endian;
	int		width;
	int		height;
}				t_img;

typedef struct s_map
{
	int		index;
	int		line_len;
	int		index_max;
}				t_map;

typedef struct s_player
{
	t_img	img;
	int		pos_x;
	int		pos_y;
	int		player_num;
	float	smooth_x;
	float	smooth_y;
}			t_player;

typedef struct s_collection
{
	int						pos_x;
	int						pos_y;
	int						collection_num;
	struct s_collection		*next;
}				t_collection;

typedef struct s_collection_list
{
	int				is_empty;
	t_collection	*first;
	t_img			img;
}				t_collection_list;

typedef struct s_exit
{
	int				pos_x;
	int				pos_y;
	int				exit_num;
	struct s_exit	*next;
}				t_exit;

typedef struct s_exit_list
{
	int		is_empty;
	t_exit	*first;
	t_img	img;
}				t_exit_list;

typedef struct s_v
{
	int	x;
	int	y;
	int	i;
	int	j;
	int	an;
}				t_v;

typedef struct s_draw
{
	int		x;
	int		y;
	int		color;
	int		pos_x;
	int		pos_y;
	int		p_data_x;
	int		p_data_y;
	float	r_y;
	float	r_x;
}				t_draw;
typedef struct s_var
{
	void	*mlx;
	void	*win;
}				t_var;
typedef struct s_info
{
	char				*tmp;
	char				**mapver;
	int					moves;
	int					m_x1;
	int					m_y1;
	int					m_x;
	int					m_y;
	int					is_zero;
	int					p;
	int					c_num;
	int					e_num;
	unsigned int		frame;
	t_player			*player;
	t_collection_list	*collection_list;
	t_exit_list			*exit_list;
	t_img				*img;
	t_img				*floor;
	t_img				*bottom;
	t_var				*var;
	t_map				*map;
	t_key				key;
}				t_info;

void			check_player(t_info *info, int pos_x);
void			split_map(t_info *info);
void			free_map1(t_info *info);
void			free_img(t_info *info);
void			free_exit_list(t_exit_list *list);
void			free_collection_list(t_collection_list *list);
void			free_memory(t_info *info);
void			init_player(t_info *info);
void			init_collection_list(t_collection_list *list);
void			init_exit_list(t_exit_list *list);
void			set_pixel(t_img *img, int x, int y, int color);
void			init_img(t_info *info);
void			init_map1(t_info *info);
void			init_var(t_info *info);
void			init_key(t_info *info);
void			push_c_list(t_info *info, int x, int y);
void			push_e_list(t_info *info, int x, int y);
void			is_collectible_char(t_info *info, char **map, int i, int j);
void			is_exit_char(t_info *info, char **map, int i, int j);
void			is_player_char(t_info *info, char **map, int i, int j);
void			check_elements(t_info *info);
void			ft_element(t_info *info);
void			init_player_image(t_info *info);
void			init_floor_image(t_info *info);
void			init_wall_image(t_info *info);
void			init_exit_image(t_info *info);
void			init_collection_image(t_info *info);
void			display_moves(t_info *info);
void			my_mlx_pixel_put(t_img *img, int x, int y, int color);
void			draw_on_img(t_img *img, t_img *img2, int x, int y);
void			ft_player_draw(t_info *info);
void			other_keys(int key, t_info *info);
void			ft_draw(t_info *info);
void			put_num(int *g_dirx, int *g_diry);
void			init_put_num(t_info *info);
void			set_to_true(t_info *info);
void			main_loop(t_info *info);
void			main_errors(t_info *info);
char			*ft_strdup(const char *s);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_substr(char const *s, unsigned int start, size_t len);
char			**ft_split(char const *s, char c);
char			**init_map(char **map, t_info *info);
int				treat_description(char *file_name, t_info *info);
int				cub_exit(void);
int				loop(t_info *info);
int				mlx_initial(t_info *info);
int				check_mapline(t_info *info, char **map);
int				parse_line(char *line, t_info *info);
int				find_player_pos(char a);
int				file_name_check(char *filename);
int				file_exists(char *file_name);
int				is_space(char c);
int				is_map_character(char c);
int				ft_isdigit(int c);
int				ft_strlen(char *str);
int				map_checker2(t_info *info, char **test_map);
int				check_map(char **map, int x, int y, int *p);
int				free_map(char **map, int cnt);
int				map_checker(t_info *info);
int				save_map1(char *line, t_info *info);
int				get_pixel(t_img *img, int x, int y);
int				is_collectible(t_info *info, int i, int j);
int				is_exit(t_info *info, int i, int j);
int				c_list_length(t_collection_list *list);
int				c_all_touched(t_info *info);
int				key_hook(int key, t_info *info);
int				close_clean(t_info *info);
size_t			ft_strlcpy(char *dest, const char *src, size_t num);
t_img			load_image(void *mlx, char *path);
t_info			*init_memory(void);
t_collection	*get_collectible(t_info *info, int i, int j);

#endif
