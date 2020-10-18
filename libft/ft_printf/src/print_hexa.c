/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awafflar <awafflar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 16:06:02 by awafflar          #+#    #+#             */
/*   Updated: 2019/10/14 12:04:18 by awafflar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_core.h"

void			print_hexa_upper(t_buffer *buff, t_fmt *fmt, t_args *args)
{
	fmt->flags |= F_UPPER;
	print_hexa(buff, fmt, args);
}

void			print_hexa(t_buffer *buff, t_fmt *fmt, t_args *args)
{
	t_fields	field;

	fields_init(&field);
	if (fmt->flags & F_PRECI && fmt->flags & F_ZERO)
		fmt->flags &= ~F_ZERO;
	field.value = get_str_from_oux_lenght(fmt, args, 16);
	if (fmt->flags & F_SHARP && field.value[0] != '0')
		field.prefix = (fmt->flags & F_UPPER ? "0X" : "0x");
	if (fmt->flags & F_PRECI && fmt->precision == 0 && field.value[0] == 0)
	{
		field.value = "";
		field.prefix = "";
	}
	print__(buff, fmt, &field);
}
