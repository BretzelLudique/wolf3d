/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fields.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awafflar <awafflar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/06 18:09:28 by awafflar          #+#    #+#             */
/*   Updated: 2019/10/14 12:39:25 by awafflar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_core.h"

void		fields_init(t_fields *f)
{
	f->prefix = "";
	f->use_precision = ADD_ZERO;
	f->free = 0;
	f->is_char = 0;
}
