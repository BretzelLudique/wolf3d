/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_tostring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awafflar <awafflar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 18:28:41 by awafflar          #+#    #+#             */
/*   Updated: 2019/10/15 14:31:40 by awafflar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_core.h"

void			f_double_tostring(t_args *args, t_fmt *fmt, t_fields *fields)
{
	double		d;

	if (fmt->arg_n != 0)
		d = va_getarg_double(args->ap, fmt->arg_n);
	else
		d = va_getarg_double(args->ap, args->current++);
	if (1 / d < 0)
	{
		d = -d;
		fields->prefix = "-";
	}
	else if (fmt->flags & F_PLUS)
		fields->prefix = "+";
	else if (fmt->flags & F_SPACE)
		fields->prefix = " ";
	if (double_exception(d, fields))
		return ;
	fields->value = ft_dtoa(d, fmt->precision, fmt->flags & F_SHARP);
	fields->free = 1;
}

void			f_ldouble_tostring(t_args *args, t_fmt *fmt, t_fields *fields)
{
	long double	d;

	if (fmt->arg_n != 0)
		d = va_getarg_long_double(args->ap, fmt->arg_n);
	else
		d = va_getarg_long_double(args->ap, args->current++);
	if (1 / d < 0)
	{
		d = -d;
		fields->prefix = "-";
	}
	else if (fmt->flags & F_PLUS)
		fields->prefix = "+";
	else if (fmt->flags & F_SPACE)
		fields->prefix = " ";
	if (ldouble_exception(d, fields))
		return ;
	fields->value = ft_ldtoa(d, fmt->precision, fmt->flags & F_SHARP);
	fields->free = 1;
}
