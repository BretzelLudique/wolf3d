/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czhang <czhang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/13 15:35:50 by czhang            #+#    #+#             */
/*   Updated: 2020/06/13 15:35:51 by czhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "wolf3d.h"

int		collision(t_data *d, t_pos *pos)
{
	if (*d->map->map[pos->y / CENTI][pos->x / CENTI] == d->map->wall)
	{
		if (pos->x == ((pos->x / CENTI) * CENTI))
			return (1);
		else if (pos->x == (((pos->x / CENTI) + 1) * CENTI - 1))
			return (2);
		else if (pos->y == ((pos->y / CENTI) * CENTI))
			return (3);
		else if (pos->y == (((pos->y / CENTI) + 1) * CENTI - 1))
			return (4);
		else
			return (5);
	}
	return (0);
}

void	move_on(t_data *d)
{
	t_pos	pos;
	double	alpha;

	pos.x = d->map->pos->x;
	pos.y = d->map->pos->y;
	alpha = d->map->alpha;
	pos.x = d->map->pos->x + (int)(cos(alpha) * 32);
	pos.y = d->map->pos->y + (int)(sin(alpha) * 32);
	if (collision(d, &pos) == 0)
	{
		d->map->pos->x = pos.x;
		d->map->pos->y = pos.y;
	}
}

void	move_back(t_data *d)
{
	t_pos	pos;
	double	alpha;

	pos.x = d->map->pos->x;
	pos.y = d->map->pos->y;
	alpha = d->map->alpha;
	pos.x = d->map->pos->x - (int)(cos(alpha) * 32);
	pos.y = d->map->pos->y - (int)(sin(alpha) * 32);
	if (collision(d, &pos) == 0)
	{
		d->map->pos->x = pos.x;
		d->map->pos->y = pos.y;
	}
}

void	turn_right(t_data *d)
{
	d->map->alpha += DEG_TO_RAD * 4;
}

void	turn_left(t_data *d)
{
	d->map->alpha -= DEG_TO_RAD * 4;
}
