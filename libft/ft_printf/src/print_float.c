/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_float.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awafflar <awafflar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/06 16:52:58 by awafflar          #+#    #+#             */
/*   Updated: 2019/10/15 15:50:54 by awafflar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_core.h"

static void		nan_inf_case(t_fmt *fmt)
{
	fmt->flags &= ~F_ZERO;
	fmt->flags &= ~F_PRECI;
	fmt->precision = 0;
}

void			print_float(t_buffer *buff, t_fmt *fmt, t_args *args)
{
	t_fields	fields;

	fields_init(&fields);
	get_str_from_f_lenght(fmt, args, &fields);
	if (ft_strcmp(fields.value, "nan") == 0
			|| ft_strcmp(fields.value, "inf") == 0
			|| ft_strcmp(fields.value, "-inf") == 0)
		nan_inf_case(fmt);
	print__(buff, fmt, &fields);
}
