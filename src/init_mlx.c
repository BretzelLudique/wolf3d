/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czhang <czhang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/13 15:35:24 by czhang            #+#    #+#             */
/*   Updated: 2020/06/13 15:35:25 by czhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		expose_hook(t_data *d)
{
	clear_draw(d);
	draw(d);
	mlx_put_image_to_window(d->mlx, d->win, d->img, 0, 0);
	return (0);
}

int		key_press(int keycode, t_data *d)
{
	if (keycode == KEY_ESC)
		quit(d);
	if (keycode == KEY_UP)
		d->save[0] = 1;
	if (keycode == KEY_DOWN)
		d->save[1] = 1;
	if (keycode == KEY_LEFT)
		d->save[2] = 1;
	if (keycode == KEY_RIGHT)
		d->save[3] = 1;
	if (keycode == 104)
		d->save[4] = (d->save[4] == 0 ? 1 : 0);
	if (keycode == KEY_RUN)
		d->save[5] = 1;
	return (0);
}

int		key_release(int keycode, t_data *d)
{
	if (keycode == KEY_UP || keycode == 119)
		d->save[0] = 0;
	if (keycode == KEY_DOWN || keycode == 115)
		d->save[1] = 0;
	if (keycode == KEY_LEFT || keycode == 97)
		d->save[2] = 0;
	if (keycode == KEY_RIGHT || keycode == 100)
		d->save[3] = 0;
	if (keycode == KEY_RUN)
		d->save[5] = 0;
	return (0);
}

int		loop_hook(t_data *d)
{
	if (d->save[0] == 1)
		move_on(d);
	if (d->save[1] == 1)
		move_back(d);
	if (d->save[2] == 1)
		turn_left(d);
	if (d->save[3] == 1)
		turn_right(d);
	expose_hook(d);
	return (0);
}

void	mlx(t_data *d)
{
	d->mlx = mlx_init();
	d->x = 0;
	d->y = 0;
	d->width = WIDTH;
	d->height = HEIGHT;
	d->win = mlx_new_window(d->mlx, WIDTH, HEIGHT, "wolf3d");
	d->img = mlx_new_image(d->mlx, WIDTH, HEIGHT);
	d->data = mlx_get_data_addr(d->img, &d->bpp, &d->size_line, &d->endian);
	mlx_expose_hook(d->win, expose_hook, d);
	mlx_hook(d->win, 2, 1, key_press, d);
	mlx_hook(d->win, 3, 2, key_release, d);
	mlx_loop_hook(d->mlx, loop_hook, d);
	mlx_loop(d->mlx);
}
