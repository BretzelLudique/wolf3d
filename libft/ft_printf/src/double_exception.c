/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_exception.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awafflar <awafflar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 14:57:38 by awafflar          #+#    #+#             */
/*   Updated: 2019/10/15 15:48:07 by awafflar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <float.h>

#include "ft_printf_core.h"

int			double_exception(double d, t_fields *fields)
{
	if (d != d)
	{
		fields->prefix = "";
		fields->value = "nan";
		return (1);
	}
	else if (d == -1.0 / 0.0)
	{
		fields->prefix = "";
		fields->value = "-inf";
		return (1);
	}
	else if (d >= DBL_MAX)
	{
		fields->value = "inf";
		return (1);
	}
	return (0);
}

int			ldouble_exception(long double d, t_fields *fields)
{
	if (d != d)
	{
		fields->prefix = "";
		fields->value = "nan";
		return (1);
	}
	else if (d <= -LDBL_MAX)
	{
		fields->prefix = "";
		fields->value = "-inf";
		return (1);
	}
	else if (d >= LDBL_MAX)
	{
		fields->value = "inf";
		return (1);
	}
	return (0);
}
