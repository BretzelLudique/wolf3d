/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awafflar <awafflar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/06 18:03:03 by awafflar          #+#    #+#             */
/*   Updated: 2019/10/14 12:43:28 by awafflar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "ft_printf_core.h"

static void		fsize_compute(t_fmt *fmt, t_fields *fields, t_fsize *fsize)
{
	if (fmt->flags & F_PRECI)
	{
		if (fields->use_precision == CUT_STRING)
			fsize->val = (fsize->val > fmt->precision ? fmt->precision :
				fsize->val);
		else if (fields->use_precision == ADD_ZERO &&
				fmt->precision > fsize->val)
			fsize->n_zero = fmt->precision - fsize->val;
	}
	if (fields->prefix[0] == '0' && fields->prefix[1] == '\0' &&
			fsize->n_zero != 0)
		fsize->n_zero--;
	fsize->wop = fsize->val + fsize->n_zero + ft_strlen(fields->prefix);
	fsize->padd = (fmt->width > fsize->wop ? fmt->width - fsize->wop : 0);
}

void			print__(t_buffer *buff, t_fmt *fmt, t_fields *fields)
{
	t_fsize		fsize;
	char		padd_char;

	fsize.val = (fields->is_char ? 1 : ft_strlen(fields->value));
	fsize.n_zero = 0;
	padd_char = (fmt->flags & F_ZERO ? '0' : ' ');
	fsize_compute(fmt, fields, &fsize);
	if ((!(fmt->flags & F_ZERO) || fields->prefix[0] == '\0') &&
			!(fmt->flags & F_MINUS))
		buff_addnchar(buff, padd_char, fsize.padd);
	buff_addstr(buff, fields->prefix);
	if (fmt->flags & F_ZERO && fields->prefix[0] != '\0' &&
			!(fmt->flags & F_MINUS))
		buff_addnchar(buff, padd_char, fsize.padd);
	buff_addnchar(buff, '0', fsize.n_zero);
	if (fields->is_char)
		buff_addchar(buff, fields->value[0]);
	else
		buff_addnstr(buff, fields->value, fsize.val);
	if (fmt->flags & F_MINUS)
		buff_addnchar(buff, padd_char, fsize.padd);
	if (fields->free)
		free(fields->value);
}
