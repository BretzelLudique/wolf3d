/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_args_misc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awafflar <awafflar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 14:31:00 by awafflar          #+#    #+#             */
/*   Updated: 2019/11/14 04:57:54 by awafflar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_core.h"

char				*va_getarg_str(va_list ap, int argn)
{
	va_list			ap_tmp;
	char			*ret;

	ret = NULL;
	va_copy(ap_tmp, ap);
	while (argn--)
		ret = va_arg(ap_tmp, char *);
	va_end(ap_tmp);
	if (ret == NULL)
		return ("(null)");
	return (ret);
}

void				*va_getarg_ptr(va_list ap, int argn)
{
	va_list			ap_tmp;
	void			*ret;

	ret = NULL;
	va_copy(ap_tmp, ap);
	while (argn--)
		ret = va_arg(ap_tmp, void *);
	va_end(ap_tmp);
	return (ret);
}

double				va_getarg_double(va_list ap, int argn)
{
	va_list			ap_tmp;
	double			ret;

	ret = 0.;
	va_copy(ap_tmp, ap);
	while (argn--)
		ret = va_arg(ap_tmp, double);
	va_end(ap_tmp);
	return (ret);
}

long double			va_getarg_long_double(va_list ap, int argn)
{
	va_list			ap_tmp;
	long double		ret;

	ret = 0.L;
	va_copy(ap_tmp, ap);
	while (argn--)
		ret = va_arg(ap_tmp, long double);
	va_end(ap_tmp);
	return (ret);
}
