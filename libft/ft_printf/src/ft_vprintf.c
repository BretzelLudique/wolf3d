/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awafflar <awafflar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 14:30:44 by awafflar          #+#    #+#             */
/*   Updated: 2019/10/01 12:29:18 by awafflar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "ft_printf_core.h"

int		ft_vprintf(const char *format, va_list ap)
{
	return (ft_vfdprintf(1, format, ap));
}

int		ft_vfdprintf(int fd, const char *format, va_list ap)
{
	t_buffer	buff;
	char		*str;
	size_t		buff_size;

	buff_size = 64;
	if (!(str = (char*)malloc(buff_size * sizeof(char))))
		return (-1);
	buff.fd = fd;
	buff_init(&buff, FD, str, buff_size);
	ft_printf__(&buff, format, ap);
	free(str);
	return (buff.total);
}

int		ft_vsprintf(char *str, const char *format, va_list ap)
{
	t_buffer	buff;

	buff.fd = 0;
	buff_init(&buff, STR, str, 0);
	ft_printf__(&buff, format, ap);
	return (buff.total);
}

int		ft_vsnprintf(char *str, size_t size, const char *format, va_list ap)
{
	t_buffer	buff;

	buff.fd = 0;
	buff_init(&buff, NSTR, str, size);
	ft_printf__(&buff, format, ap);
	return (buff.total);
}
