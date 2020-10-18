/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lines_blocks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czhang <czhang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/13 15:35:30 by czhang            #+#    #+#             */
/*   Updated: 2020/06/15 23:32:30 by czhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "wolf3d.h"

void			init_pos(int x, int y, t_pos *pos)
{
	pos->x = x;
	pos->y = y;
}

static t_line	*init_line(void)
{
	t_line		*line;

	if ((!(line = (t_line *)malloc(sizeof(t_line))))
		|| (!(line->a = (t_pos *)malloc(sizeof(t_pos))))
		|| (!(line->b = (t_pos *)malloc(sizeof(t_pos)))))
	{
		free_line(line);
		return (0);
	}
	line->a->x = 0;
	line->a->y = 0;
	line->b->x = 0;
	line->b->y = 0;
	return (line);
}

int				init_block(t_data *d)
{
	t_block *block;

	if (!(block = (t_block *)malloc(sizeof(t_block))))
		return (0);
	block->l1 = NULL;
	block->l2 = NULL;
	block->l3 = NULL;
	block->l4 = NULL;
	if ((!(block->l1 = init_line()))
		|| (!(block->l2 = init_line()))
		|| (!(block->l3 = init_line()))
		|| (!(block->l4 = init_line())))
	{
		free_block(block);
		return (0);
	}
	d->block = block;
	return (1);
}
