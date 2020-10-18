/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_star.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awafflar <awafflar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 15:32:56 by awafflar          #+#    #+#             */
/*   Updated: 2019/10/15 15:49:51 by awafflar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>

#include "ft_printf_core.h"

void		parse_star(t_fmt *fmt, const char **format, t_args *args, t_ptype t)
{
	int		check_arg;

	if (t == WIDTH)
	{
		check_arg = va_getarg_int(args->ap, args->current);
		fmt->width = (check_arg >= 0 ? (size_t)check_arg : (size_t)-check_arg);
		if (check_arg < 0)
			fmt->flags |= F_MINUS;
		args->current++;
		(*format)++;
	}
	else if (t == PRECISION)
	{
		check_arg = va_getarg_int(args->ap, args->current++);
		fmt->precision = (check_arg >= 0 ? (size_t)check_arg : 0);
		if (check_arg < 0)
			fmt->flags &= ~F_PRECI;
	}
}

void		parse_dol_w_star(t_fmt *fmt, t_args *args, int n)
{
	int		check_arg;

	check_arg = va_getarg_int(args->ap, n);
	fmt->width = (check_arg >= 0 ? (size_t)check_arg : 0);
}

void		parse_dol_p_star(t_fmt *fmt, t_args *args, int n)
{
	int		check_arg;

	check_arg = va_getarg_int(args->ap, n);
	fmt->precision = (check_arg >= 0 ? (size_t)check_arg : 0);
}
