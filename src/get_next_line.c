/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awafflar <awafflar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 11:50:08 by awafflar          #+#    #+#             */
/*   Updated: 2020/01/28 15:33:55 by awafflar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

#include "../includes/get_next_line.h"

char				*gnl_strjoin(char *s1, char *s2)
{
	char			*ret;
	char			*tmp;
	unsigned long	size;

	ret = s1;
	while (*ret)
		ret++;
	tmp = s2;
	while (*tmp)
		tmp++;
	size = (unsigned long)(ret - s1 + tmp - s2 + 1);
	if (!(ret = (char *)malloc(sizeof(char) * size)))
		return (NULL);
	tmp = ret;
	while ((*tmp = *s1++))
		tmp++;
	while ((*tmp = *s2++))
		tmp++;
	*tmp = '\0';
	return (ret);
}

char				*gnl_strchr(char *s)
{
	char			*begin;

	begin = s;
	while (*s)
	{
		if (*s == '\n')
		{
			*s = '\0';
			if (s > begin && *(s - 1) == '\r')
				*(s - 1) = '\0';
			return (s);
		}
		s++;
	}
	return (NULL);
}

int					gnl_read(const int fd, char **remain, char **line)
{
	char			buff[BUFF_SIZE + 1];
	ssize_t			res;
	char			*tmp;

	while ((res = read(fd, buff, BUFF_SIZE)) != 0)
	{
		if (res == -1)
			return (-1);
		buff[res] = '\0';
		if (!(*line = gnl_strjoin(*remain, buff)))
			return (-1);
		free(*remain);
		if ((tmp = gnl_strchr(*line)))
		{
			if (!(*remain = gnl_strjoin(tmp + 1, "")))
				return (-1);
			return (1);
		}
		*remain = *line;
	}
	*line = (**remain ? *remain : *line);
	if (!**remain && (res = 1))
		free(*remain);
	*remain = NULL;
	return ((int)(1 - res));
}

int					get_next_line(const int fd, char **line)
{
	static char		*remain = NULL;
	char			*tmp;

	if (!remain && !(remain = gnl_strjoin("", "")))
		return (-1);
	if ((tmp = gnl_strchr(remain)))
	{
		*line = remain;
		if (!(remain = gnl_strjoin(tmp + 1, "")))
			return (-1);
		return (1);
	}
	return (gnl_read(fd, &remain, line));
}
