/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czhang <czhang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/13 15:46:13 by czhang            #+#    #+#             */
/*   Updated: 2020/06/21 17:15:36 by czhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H

# include "../minilibx-linux/mlx.h"
# include "../libft/include/libft.h"
# include "get_next_line.h"

typedef struct	s_collision
{
	int			face;
	double		dist;
}				t_collision;

typedef struct	s_pos
{
	int			x;
	int			y;
}				t_pos;

typedef struct	s_map
{
	int			x;
	int			y;
	char		*name;
	int			wall;
	int			floor;
	int			start;
	int			end;
	double		alpha;
	int			axis_y;
	int			***map;
	t_pos		*pos;
}				t_map;

typedef struct	s_line
{
	t_pos		*a;
	t_pos		*b;
}				t_line;

typedef struct	s_block
{
	t_line		*l1;
	t_line		*l2;
	t_line		*l3;
	t_line		*l4;
}				t_block;

typedef struct	s_data
{
	void		*mlx;
	void		*win;
	void		*img;
	char		*data;
	int			bpp;
	int			size_line;
	int			endian;
	int			x;
	int			y;
	int			width;
	int			height;
	int			save[6];
	int			inter_collision;
	double		dist_screen;
	t_map		*map;
	t_block		*block;
}				t_data;

# define KEY_ESC		65307
# define KEY_UP			65362
# define KEY_DOWN		65364
# define KEY_LEFT		65361
# define KEY_RIGHT		65363
# define KEY_RUN		65505

/*
**# define KEY_ESC		53
**# define KEY_UP			126
**# define KEY_DOWN		125
**# define KEY_LEFT		123
**# define KEY_RIGHT		124
**# define KEY_RUN		56
*/

# define HEIGHT			850
# define WIDTH			1500
# define CENTI			100
# define VISION			60
# define DEG_TO_RAD		0.0174532925

void			free_map(t_map *map);
void			free_tab(char **tab);
void			free_line(t_line *line);
void			free_block(t_block *block);
int				put_error(char *str, t_data *d, char **tab, char *line);

void			get_data(t_data *d, char *av);

void			put_pixel_to_img(t_data *d, int x, int y, int color);
int				expose_hook(t_data *d);
int				mouse_hook(int button, int x, int y, t_data *d);
int				key_hook(int keycode, t_data *d);
void			mlx(t_data *d);

void			draw(t_data *d);
void			clear_draw(t_data *d);
void			clean_map(t_data *d);

void			trace_line(t_data *d, t_pos a, t_pos b, int color);
void			trace_map(t_data *d);

void			init_pos(int x, int y, t_pos *pos);
int				init_block(t_data *d);

void			swap(int *a, int *b);
void			swap_pos(t_pos *a, t_pos *b);
int				abs(int x);

int				collision(t_data *d, t_pos *pos);
void			move_on(t_data *d);
void			move_back(t_data *d);
void			turn_right(t_data *d);
void			turn_left(t_data *d);

void			search_wall(t_data *d, t_pos *pos, double a, t_collision *col);
void			vision(t_data *d);
void			print_wall(t_data *d, t_collision *col, int x);
void			floor_casting(t_data *d, t_pos *pos, t_collision *c, double a);
void			print_wend(t_data *d, double a, int dist, double dist_wall);

int				color_shadow(int color, double shadow);
int				color_norm(int red, int green, int blue);

void			quit(t_data *d);

#endif
