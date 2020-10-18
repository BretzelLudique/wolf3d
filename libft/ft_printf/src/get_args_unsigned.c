/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_args_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awafflar <awafflar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 14:31:30 by awafflar          #+#    #+#             */
/*   Updated: 2019/11/14 05:00:41 by awafflar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_core.h"

unsigned int			va_getarg_uint(va_list ap, int argn)
{
	va_list				ap_tmp;
	unsigned int		ret;

	ret = 0;
	va_copy(ap_tmp, ap);
	while (argn--)
		ret = va_arg(ap_tmp, unsigned int);
	va_end(ap_tmp);
	return (ret);
}

unsigned long			va_getarg_ulong(va_list ap, int argn)
{
	va_list				ap_tmp;
	unsigned long		ret;

	ret = 0;
	va_copy(ap_tmp, ap);
	while (argn--)
		ret = va_arg(ap_tmp, unsigned long);
	va_end(ap_tmp);
	return (ret);
}

unsigned long long		va_getarg_ulonglong(va_list ap, int argn)
{
	va_list				ap_tmp;
	unsigned long long	ret;

	ret = 0;
	va_copy(ap_tmp, ap);
	while (argn--)
		ret = va_arg(ap_tmp, unsigned long long);
	va_end(ap_tmp);
	return (ret);
}
