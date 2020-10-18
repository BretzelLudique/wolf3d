/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_binary.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awafflar <awafflar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 16:06:02 by awafflar          #+#    #+#             */
/*   Updated: 2019/10/14 11:26:55 by awafflar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_core.h"

void			print_binary_upper(t_buffer *buff, t_fmt *fmt, t_args *args)
{
	fmt->flags |= F_UPPER;
	print_binary(buff, fmt, args);
}

void			print_binary(t_buffer *buff, t_fmt *fmt, t_args *args)
{
	t_fields	field;

	fields_init(&field);
	field.prefix = (fmt->flags & F_UPPER ? "0B" : "0b");
	if (fmt->flags & F_PRECI && fmt->flags & F_ZERO)
		fmt->flags &= ~F_ZERO;
	field.value = get_str_from_oux_lenght(fmt, args, 2);
	print__(buff, fmt, &field);
}
