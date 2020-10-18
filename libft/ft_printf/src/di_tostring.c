/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   di_tostring.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awafflar <awafflar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 17:23:51 by awafflar          #+#    #+#             */
/*   Updated: 2019/10/23 18:28:49 by awafflar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_core.h"
#include "libft.h"

char				*di_char_tostring(t_args *args, t_fmt *fmt)
{
	char			n;

	if (fmt->arg_n != 0)
		n = (char)va_getarg_int(args->ap, fmt->arg_n);
	else
		n = (char)va_getarg_int(args->ap, args->current++);
	if (n == 0 && fmt->flags & F_PRECI && fmt->precision == 0)
		return ("");
	return (ft_lltostr((long long)n));
}

char				*di_short_tostring(t_args *args, t_fmt *fmt)
{
	short			n;

	if (fmt->arg_n != 0)
		n = (short)va_getarg_int(args->ap, fmt->arg_n);
	else
		n = (short)va_getarg_int(args->ap, args->current++);
	if (n == 0 && fmt->flags & F_PRECI && fmt->precision == 0)
		return ("");
	return (ft_lltostr((long long)n));
}

char				*di_int_tostring(t_args *args, t_fmt *fmt)
{
	int			n;

	if (fmt->arg_n != 0)
		n = (int)va_getarg_int(args->ap, fmt->arg_n);
	else
		n = (int)va_getarg_int(args->ap, args->current++);
	if (n == 0 && fmt->flags & F_PRECI && fmt->precision == 0)
		return ("");
	return (ft_lltostr((long long)n));
}

char				*di_long_tostring(t_args *args, t_fmt *fmt)
{
	long			n;

	if (fmt->arg_n != 0)
		n = (long)va_getarg_long(args->ap, fmt->arg_n);
	else
		n = (long)va_getarg_long(args->ap, args->current++);
	if (n == 0 && fmt->flags & F_PRECI && fmt->precision == 0)
		return ("");
	return (ft_lltostr((long long)n));
}

char				*di_longlong_tostring(t_args *args, t_fmt *fmt)
{
	long long		n;

	if (fmt->arg_n != 0)
		n = (long long)va_getarg_longlong(args->ap, fmt->arg_n);
	else
		n = (long long)va_getarg_longlong(args->ap, args->current++);
	if (n == 0 && fmt->flags & F_PRECI && fmt->precision == 0)
		return ("");
	return (ft_lltostr(n));
}
