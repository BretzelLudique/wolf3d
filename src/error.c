/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czhang <czhang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/13 15:35:10 by czhang            #+#    #+#             */
/*   Updated: 2020/06/16 01:16:20 by czhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"
#include <stdlib.h>

void	free_map(t_map *m)
{
	int	l;
	int	i;

	if (!m)
		return ;
	if (m->name)
		free(m->name);
	if (m->pos)
		free(m->pos);
	if (!(m->map))
	{
		free(m);
		return ;
	}
	l = -1;
	while (m->map[++l])
	{
		i = -1;
		while (m->map[l][++i])
			free(m->map[l][i]);
		free(m->map[l]);
	}
	free(m->map);
	free(m);
}

void	free_tab(char **tab)
{
	int	i;

	i = -1;
	while (tab[++i])
		free(tab[i]);
	free(tab);
}

void	free_line(t_line *line)
{
	if (!line)
		return ;
	if (line->b)
		free(line->b);
	if (line->a)
		free(line->a);
	free(line);
}

void	free_block(t_block *block)
{
	if (!block)
		return ;
	free_line(block->l4);
	free_line(block->l3);
	free_line(block->l2);
	free_line(block->l1);
	free(block);
}

int		put_error(char *str, t_data *d, char **tab, char *line)
{
	ft_putendl(str);
	if (line)
		free(line);
	if (tab)
		free_tab(tab);
	if (d)
	{
		free_block(d->block);
		free_map(d->map);
	}
	exit(0);
}
