/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czhang <czhang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/13 15:35:35 by czhang            #+#    #+#             */
/*   Updated: 2020/06/16 00:17:16 by czhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"
#include <stdlib.h>

static t_data	init_t_data(t_data *d)
{
	d->mlx = NULL;
	d->win = NULL;
	d->img = NULL;
	d->data = NULL;
	d->map = NULL;
	d->block = NULL;
	return (*d);
}

void			quit(t_data *d)
{
	free_block(d->block);
	free_map(d->map);
	exit(0);
}

int				main(int ac, char **av)
{
	t_data	d;

	if (ac != 2)
		put_error("usage : ./wolf3d map", 0, 0, 0);
	d = init_t_data(&d);
	if (!(init_block(&d)))
		put_error("error malloc block", &d, 0, 0);
	get_data(&d, av[1]);
	ft_memset(d.save, 0, sizeof(int) * 6);
	mlx(&d);
	return (0);
}
