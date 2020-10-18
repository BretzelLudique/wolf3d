/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czhang <czhang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/13 15:35:57 by czhang            #+#    #+#             */
/*   Updated: 2020/06/15 23:55:47 by czhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stdlib.h>
#include "wolf3d.h"

void	search_wall(t_data *d, t_pos *pos, double alpha, t_collision *col)
{
	int		dist;
	double	x;
	double	y;
	int		colli;
	int		rm;

	dist = 0;
	x = (double)pos->x;
	y = (double)pos->y;
	d->inter_collision = 0;
	rm = HEIGHT / d->map->y / 5;
	while ((colli = collision(d, pos)) <= 0)
	{
		if (d->save[4])
			put_pixel_to_img(d, (pos->x * rm) / CENTI, (pos->y * rm) / CENTI,
			colli == -1 ? 0x23eb67 : 0xFFFFFF);
		d->inter_collision = (colli < 0) ? colli : d->inter_collision;
		pos->x = (int)x;
		pos->y = (int)y;
		x = x + (cos(alpha) * 1);
		y = y + (sin(alpha) * 1);
		dist += 1;
	}
	col->face = colli;
	col->dist = (double)dist;
}

void	vision(t_data *d)
{
	t_pos		*pos;
	double		alpha;
	int			x;
	t_collision	*col;

	d->dist_screen = (WIDTH / 2) / tan((VISION * DEG_TO_RAD) / 2);
	pos = (t_pos *)malloc(sizeof(t_pos));
	col = (t_collision *)malloc(sizeof(t_collision));
	init_pos(d->map->pos->x, d->map->pos->y, pos);
	x = -(WIDTH / 2) - 1;
	while (++x <= (WIDTH / 2))
	{
		alpha = d->map->alpha + atan(x / d->dist_screen);
		search_wall(d, pos, alpha, col);
		col->dist = col->dist * cos(atan(x / d->dist_screen));
		print_wall(d, col, x + (WIDTH / 2) - 1);
		floor_casting(d, pos, col, alpha);
		pos->x = d->map->pos->x;
		pos->y = d->map->pos->y;
	}
	free(pos);
	free(col);
}

void	print_wall(t_data *d, t_collision *col, int x)
{
	double	height;
	t_pos	a;
	t_pos	b;
	int		ya;
	int		yb;

	height = ((d->dist_screen * (double)HEIGHT) / col->dist);
	height = height / 10;
	ya = (d->map->axis_y - (int)(height / 2));
	ya = (ya <= 0 ? 1 : ya);
	yb = (d->map->axis_y + (int)(height / 2));
	yb = (yb >= HEIGHT ? HEIGHT : yb);
	init_pos(x, ya, &a);
	init_pos(x, yb, &b);
	if (col->face == 1)
		trace_line(d, a, b, color_shadow(0xFF0000, 500 / col->dist));
	else if (col->face == 2)
		trace_line(d, a, b, color_shadow(0x00FF00, 500 / col->dist));
	else if (col->face == 3)
		trace_line(d, a, b, color_shadow(0x0000FF, 500 / col->dist));
	else if (col->face == 4)
		trace_line(d, a, b, color_shadow(0xFF7F00, 500 / col->dist));
	else
		trace_line(d, a, b, color_shadow(0xFFFFFF, 500 / col->dist));
}

void	floor_casting(t_data *d, t_pos *pos, t_collision *col, double alpha)
{
	int		dist;
	double	x;
	double	y;
	int		colli;

	if (d->inter_collision == 0)
		return ;
	dist = 0;
	x = (double)pos->x;
	y = (double)pos->y;
	while ((colli = collision(d, pos)) <= 0)
	{
		if (colli < 0)
			print_wend(d, alpha, dist, col->dist);
		pos->x = (int)x;
		pos->y = (int)y;
		x = x + (cos(alpha) * 1);
		y = y + (sin(alpha) * 1);
		dist += 1;
	}
}

void	print_wend(t_data *d, double alpha, int dist, double dist_wall)
{
	double	h;
	double	dist_wall_screen;
	double	dist_floor_screen;
	double	y;
	double	x;

	h = ((d->dist_screen * (double)HEIGHT) / dist_wall) / 20;
	dist_wall_screen = (((double)HEIGHT / 2) / sin(alpha)) - h / sin(alpha);
	dist_floor_screen = dist * dist_wall_screen / dist_wall;
	y = (HEIGHT - dist_floor_screen * sin(alpha)) / 2 + HEIGHT / 2;
	x = WIDTH / 2 + dist_floor_screen * cos(alpha);
	x = (x >= WIDTH ? WIDTH : x);
	x = x < 0 ? 0 : x;
	y = (y >= HEIGHT ? HEIGHT : y);
	y = y < 0 ? 0 : y;
	put_pixel_to_img(d, (int)x, (int)y, 0x23eb67);
}
