/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   total_to_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awafflar <awafflar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/04 10:32:12 by awafflar          #+#    #+#             */
/*   Updated: 2019/10/14 11:42:33 by awafflar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>

#include "ft_printf_core.h"

void			n_char_ptr(t_buffer *buff, t_fmt *fmt, t_args *args)
{
	char		*ptr;

	if (fmt->arg_n != 0)
		ptr = (char *)va_getarg_ptr(args->ap, fmt->arg_n);
	else
		ptr = (char *)va_getarg_ptr(args->ap, args->current++);
	*ptr = (char)buff->total;
}

void			n_short_ptr(t_buffer *buff, t_fmt *fmt, t_args *args)
{
	short		*ptr;

	if (fmt->arg_n != 0)
		ptr = (short *)va_getarg_ptr(args->ap, fmt->arg_n);
	else
		ptr = (short *)va_getarg_ptr(args->ap, args->current++);
	*ptr = (short)buff->total;
}

void			n_int_ptr(t_buffer *buff, t_fmt *fmt, t_args *args)
{
	int			*ptr;

	if (fmt->arg_n != 0)
		ptr = (int *)va_getarg_ptr(args->ap, fmt->arg_n);
	else
		ptr = (int *)va_getarg_ptr(args->ap, args->current++);
	*ptr = buff->total;
}

void			n_long_ptr(t_buffer *buff, t_fmt *fmt, t_args *args)
{
	long		*ptr;

	if (fmt->arg_n != 0)
		ptr = (long *)va_getarg_ptr(args->ap, fmt->arg_n);
	else
		ptr = (long *)va_getarg_ptr(args->ap, args->current++);
	*ptr = (long)buff->total;
}

void			n_longlong_ptr(t_buffer *buff, t_fmt *fmt, t_args *args)
{
	long long	*ptr;

	if (fmt->arg_n != 0)
		ptr = (long long *)va_getarg_ptr(args->ap, fmt->arg_n);
	else
		ptr = (long long *)va_getarg_ptr(args->ap, args->current++);
	*ptr = (long long)buff->total;
}
