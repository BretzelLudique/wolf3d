/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czhang <czhang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/13 15:35:04 by czhang            #+#    #+#             */
/*   Updated: 2020/06/15 14:46:20 by czhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	put_pixel_to_img(t_data *d, int x, int y, int color)
{
	unsigned int	mgcv;
	int				i;

	mgcv = mlx_get_color_value(d->mlx, color);
	i = x * 4 + y * d->size_line;
	d->data[i] = (mgcv & 0xFF);
	d->data[i + 1] = (mgcv & 0xFF00) >> 8;
	d->data[i + 2] = (mgcv & 0xFF0000) >> 16;
}

void	clean_map(t_data *d)
{
	int		x;
	int		y;

	x = -1;
	while (++x <= WIDTH / 5)
	{
		y = -1;
		while (++y <= HEIGHT / 5)
			put_pixel_to_img(d, x, y, 0x000000);
	}
}

void	draw(t_data *d)
{
	int	rm;

	rm = HEIGHT / d->map->y / 5;
	vision(d);
	put_pixel_to_img(d, d->map->pos->x * rm / CENTI,
		(d->map->pos->y * rm) / CENTI, 0x000000);
	trace_map(d);
}

void	clear_draw(t_data *d)
{
	int		x;
	int		y;

	x = -1;
	while (++x <= WIDTH)
	{
		y = -1;
		while (++y <= (HEIGHT / 2))
			put_pixel_to_img(d, x, y, 0xBBBBBB);
		while (++y <= HEIGHT)
			put_pixel_to_img(d, x, y, 0x444444);
	}
}
