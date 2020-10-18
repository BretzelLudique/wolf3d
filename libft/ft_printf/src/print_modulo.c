/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_modulo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awafflar <awafflar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 14:31:50 by awafflar          #+#    #+#             */
/*   Updated: 2019/10/07 15:09:14 by awafflar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_core.h"

void			print_modulo(t_buffer *buff, t_fmt *fmt, t_args *args)
{
	t_fields	fields;

	(void)args;
	fields_init(&fields);
	fields.value = "%";
	print__(buff, fmt, &fields);
}
