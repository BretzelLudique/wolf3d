/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   oux_tostring.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awafflar <awafflar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 17:01:27 by awafflar          #+#    #+#             */
/*   Updated: 2019/10/14 11:42:04 by awafflar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_core.h"

char			*oux_uchar_tostring(t_args *args, t_fmt *fmt, unsigned int base,
					char *digits)
{
	unsigned char		n;

	if (fmt->arg_n != 0)
		n = (unsigned char)va_getarg_uint(args->ap, fmt->arg_n);
	else
		n = (unsigned char)va_getarg_uint(args->ap, args->current++);
	if (n == 0 && fmt->flags & F_PRECI && fmt->precision == 0)
		return ("");
	return (ft_ulltostr_base((unsigned long long)n, base, digits));
}

char			*oux_ushort_tostring(t_args *args, t_fmt *fmt,
					unsigned int base, char *digits)
{
	unsigned short		n;

	if (fmt->arg_n != 0)
		n = (unsigned short)va_getarg_uint(args->ap, fmt->arg_n);
	else
		n = (unsigned short)va_getarg_uint(args->ap, args->current++);
	if (n == 0 && fmt->flags & F_PRECI && fmt->precision == 0)
		return ("");
	return (ft_ulltostr_base((unsigned long long)n, base, digits));
}

char			*oux_uint_tostring(t_args *args, t_fmt *fmt, unsigned int base,
					char *digits)
{
	unsigned int		n;

	if (fmt->arg_n != 0)
		n = va_getarg_uint(args->ap, fmt->arg_n);
	else
		n = va_getarg_uint(args->ap, args->current++);
	if (n == 0 && fmt->flags & F_PRECI && fmt->precision == 0)
		return ("");
	return (ft_ulltostr_base((unsigned long long)n, base, digits));
}

char			*oux_ulong_tostring(t_args *args, t_fmt *fmt, unsigned int base,
					char *digits)
{
	unsigned long		n;

	if (fmt->arg_n != 0)
		n = (unsigned long)va_getarg_ulong(args->ap, fmt->arg_n);
	else
		n = (unsigned long)va_getarg_ulong(args->ap, args->current++);
	if (n == 0 && fmt->flags & F_PRECI && fmt->precision == 0)
		return ("");
	return (ft_ulltostr_base((unsigned long long)n, base, digits));
}

char			*oux_ulonglong_tostring(t_args *args, t_fmt *fmt,
					unsigned int base, char *digits)
{
	unsigned long long	n;

	if (fmt->arg_n != 0)
		n = (unsigned long long)va_getarg_ulonglong(args->ap, fmt->arg_n);
	else
		n = (unsigned long long)va_getarg_ulonglong(args->ap, args->current++);
	if (n == 0 && fmt->flags & F_PRECI && fmt->precision == 0)
		return ("");
	return (ft_ulltostr_base((unsigned long long)n, base, digits));
}
