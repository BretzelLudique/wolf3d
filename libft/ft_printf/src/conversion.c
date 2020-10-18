/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awafflar <awafflar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 15:27:36 by awafflar          #+#    #+#             */
/*   Updated: 2019/10/15 14:30:26 by awafflar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_core.h"

static char		*(*g_oux_tostring[6])(t_args *, t_fmt *fmt, unsigned int,
				char *) =
{
	oux_uint_tostring, oux_uchar_tostring, oux_ushort_tostring,
	oux_ulong_tostring, oux_ulonglong_tostring, oux_uint_tostring
};

static char		*(*g_di_tostring[6])(t_args *, t_fmt *) =
{
	di_int_tostring, di_char_tostring, di_short_tostring, di_long_tostring,
	di_longlong_tostring, di_int_tostring
};

char			*get_str_from_oux_lenght(t_fmt *fmt, t_args *args,
					unsigned int base)
{
	char		*digits;

	digits = (fmt->flags & F_UPPER ? "0123456789ABCDEF" : "0123456789abcdef");
	return (g_oux_tostring[(int)fmt->lenght](args, fmt, base, digits));
}

char			*get_str_from_di_lenght(t_fmt *fmt, t_args *args)
{
	return (g_di_tostring[(int)fmt->lenght](args, fmt));
}

void			get_str_from_f_lenght(t_fmt *fmt, t_args *args, t_fields *f)
{
	fmt->precision = (fmt->flags & F_PRECI ? fmt->precision : 6);
	if (fmt->lenght == BIGL)
		f_ldouble_tostring(args, fmt, f);
	else
		f_double_tostring(args, fmt, f);
}
