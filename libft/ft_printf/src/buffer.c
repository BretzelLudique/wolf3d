/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awafflar <awafflar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 13:34:33 by awafflar          #+#    #+#             */
/*   Updated: 2019/11/14 04:59:48 by awafflar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#include "ft_printf_core.h"

void		buff_init(t_buffer *buff, t_bufftype type, char *str, size_t size)
{
	buff->type = type;
	buff->str = str;
	buff->size = (buff->type == NSTR ? size - 1 : size);
	buff->pos = 0;
	buff->total = 0;
}

void		buff_flush(t_buffer *buff)
{
	ssize_t	ret;

	ret = 0;
	if (buff->type == FD)
	{
		ret += write(buff->fd, buff->str, buff->pos);
		buff->pos = 0;
	}
	else
		buff->str[buff->pos] = '\0';
}
