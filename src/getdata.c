/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getdata.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czhang <czhang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/13 15:35:15 by czhang            #+#    #+#             */
/*   Updated: 2020/06/16 01:06:37 by czhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdlib.h>
#include "wolf3d.h"

static void	prelinit(t_data *d, char **tab)
{
	int	size;

	size = 0;
	while (tab && tab[size])
		size++;
	if (size != 7)
		put_error("error file", d, tab, 0);
	d->map->x = ft_atoi(tab[0]);
	d->map->y = ft_atoi(tab[1]);
	if (!(d->map->name = ft_strdup(tab[2])))
		put_error("error strdup or map name", d, tab, 0);
	d->map->wall = ft_atoi(tab[3]);
	d->map->floor = ft_atoi(tab[4]);
	d->map->start = ft_atoi(tab[5]);
	d->map->end = (tab[6]) ? ft_atoi(tab[6]) : -1;
}

static void	init_t_map(t_data *d, char **tab, char *line)
{
	int		i;
	t_map	*m;

	if (!(d->map = (t_map *)ft_memalloc(sizeof(t_map))))
		put_error("error malloc map", d, tab, line);
	m = d->map;
	prelinit(d, tab);
	if (!(m->pos = (t_pos *)ft_memalloc(sizeof(t_pos)))
		|| (!(m->map = (int ***)ft_memalloc(sizeof(int **) * (m->y + 1)))))
		put_error("error malloc map", d, tab, line);
	m->alpha = 0;
	m->axis_y = HEIGHT / 2;
	i = -1;
	while (++i < m->y)
		if (!(m->map[i] = (int **)ft_memalloc(sizeof(int *) * (m->x + 1))))
			put_error("error malloc map[line]", d, tab, line);
	m->map[m->y] = NULL;
	i = -1;
	if (!m->name || !ft_strlen(m->name) || m->wall == m->floor)
		put_error("error map file (bad info line)", d, tab, line);
	free(line);
	free_tab(tab);
}

static void	map_init(t_data *d, char *str, int line)
{
	int		i;
	char	**t;
	t_map	*m;

	m = d->map;
	if (line == m->y)
		put_error("bad ymax in 1st line of map file", d, 0, str);
	if ((int)ft_cntwrd(str, ' ') != m->x)
		put_error("bad xmax in 1st line of map file", d, 0, str);
	if (!(t = ft_strsplit(str, ' ')))
		put_error("error strsplit in map_init", d, 0, str);
	i = -1;
	while (++i < m->x)
	{
		if (!(m->map[line][i] = (int *)ft_memalloc(sizeof(int))))
			put_error("error malloc map[line][i]", d, t, str);
		*(m->map[line][i]) = ft_atoi(t[i]);
		if (*(m->map[line][i]) == m->start)
			init_pos(i * CENTI + CENTI / 2, line * CENTI + CENTI / 2, m->pos);
	}
	m->map[line][m->x] = NULL;
	free_tab(t);
	free(str);
}

void		get_data(t_data *d, char *file)
{
	int		fd;
	char	*line;
	int		i;
	char	**t;

	if ((fd = open(file, O_RDONLY)) < 0)
		put_error("error open", d, 0, 0);
	if (get_next_line(fd, &line) <= 0)
		put_error("error read gnl", d, 0, 0);
	if (!(t = ft_strsplit(line, ' ')))
		put_error("error strsplit in init_t_map", d, t, line);
	init_t_map(d, t, line);
	i = 0;
	while (i <= d->map->y && get_next_line(fd, &line) > 0)
		map_init(d, line, i++);
	if (close(fd) < 0)
		put_error("error close", d, 0, 0);
	if (i != d->map->y)
		put_error("bad ymax in 1st line of map file", d, 0, 0);
}
