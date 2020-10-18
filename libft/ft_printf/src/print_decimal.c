/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_decimal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awafflar <awafflar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 14:31:43 by awafflar          #+#    #+#             */
/*   Updated: 2019/10/14 11:36:10 by awafflar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_core.h"

void			print_decimal(t_buffer *buff, t_fmt *fmt, t_args *args)
{
	t_fields	field;

	fields_init(&field);
	field.value = get_str_from_di_lenght(fmt, args);
	if (fmt->flags & F_PRECI && fmt->flags & F_ZERO)
		fmt->flags &= ~F_ZERO;
	if (field.value[0] == '-')
	{
		field.value++;
		field.prefix = "-";
	}
	else if (fmt->flags & F_PLUS)
		field.prefix = "+";
	else if (fmt->flags & F_SPACE)
		field.prefix = " ";
	print__(buff, fmt, &field);
}
