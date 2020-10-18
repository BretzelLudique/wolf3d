/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czhang <czhang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/13 15:36:03 by czhang            #+#    #+#             */
/*   Updated: 2020/06/13 16:01:20 by czhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void		trace_line(t_data *d, t_pos a, t_pos b, int color)
{
	int		x;
	int		y;

	if (abs(b.x - a.x) >= abs(b.y - a.y))
	{
		if (a.x > b.x)
			swap_pos(&a, &b);
		x = a.x - 1;
		while (++x <= b.x)
		{
			y = a.y + ((b.y - a.y) * (x - a.x)) / (b.x - a.x);
			put_pixel_to_img(d, x, y, color);
		}
	}
	else
	{
		if (a.y > b.y)
			swap_pos(&a, &b);
		y = a.y - 1;
		while (++y <= b.y)
		{
			x = a.x + ((b.x - a.x) * (y - a.y)) / (b.y - a.y);
			put_pixel_to_img(d, x, y, color);
		}
	}
}

static void	fill_block(t_data *d, int x, int y)
{
	int	rm;

	rm = HEIGHT / d->map->y / 5;
	d->block->l1->a->x = x * rm;
	d->block->l1->a->y = y * rm;
	d->block->l1->b->x = (x + 1) * rm;
	d->block->l1->b->y = y * rm;
	d->block->l2->a->x = (x + 1) * rm;
	d->block->l2->a->y = y * rm;
	d->block->l2->b->x = (x + 1) * rm;
	d->block->l2->b->y = (y + 1) * rm;
	d->block->l3->a->x = x * rm;
	d->block->l3->a->y = y * rm;
	d->block->l3->b->x = x * rm;
	d->block->l3->b->y = (y + 1) * rm;
	d->block->l4->a->x = x * rm;
	d->block->l4->a->y = (y + 1) * rm;
	d->block->l4->b->x = (x + 1) * rm;
	d->block->l4->b->y = (y + 1) * rm;
}

static void	trace_block(t_data *d, int x, int y)
{
	if (*(d->map->map[y][x]) == d->map->wall)
	{
		fill_block(d, x, y);
		trace_line(d, *(d->block->l1->a), *(d->block->l1->b), 0x0000ff);
		trace_line(d, *(d->block->l2->a), *(d->block->l2->b), 0xff0000);
		trace_line(d, *(d->block->l3->a), *(d->block->l3->b), 0x00ff00);
		trace_line(d, *(d->block->l4->a), *(d->block->l4->b), 0xE8D630);
	}
}

void		trace_map(t_data *d)
{
	int		i;
	int		j;

	i = -1;
	j = -1;
	while (d->map->map[++i])
	{
		while (d->map->map[i][++j])
			trace_block(d, j, i);
		j = -1;
	}
}
