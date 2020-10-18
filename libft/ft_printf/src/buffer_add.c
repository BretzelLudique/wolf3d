/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer_add.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awafflar <awafflar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 14:33:30 by awafflar          #+#    #+#             */
/*   Updated: 2019/10/02 13:54:26 by awafflar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_core.h"

void		buff_addchar(t_buffer *buff, const char c)
{
	buff->total++;
	if (buff->pos == buff->size && buff->type != STR)
	{
		if (buff->type == NSTR)
			return ;
		buff_flush(buff);
	}
	buff->str[buff->pos++] = c;
}

void		buff_addnchar(t_buffer *buff, const char c, size_t n)
{
	while (n--)
		buff_addchar(buff, c);
}

void		buff_addstr(t_buffer *buff, const char *s)
{
	while (*s)
		buff_addchar(buff, *s++);
}

void		buff_addnstr(t_buffer *buff, const char *s, size_t n)
{
	while (n-- && *s)
		buff_addchar(buff, *s++);
}
