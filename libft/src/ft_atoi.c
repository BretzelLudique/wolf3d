/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awafflar <awafflar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 16:56:25 by awafflar          #+#    #+#             */
/*   Updated: 2019/10/27 04:47:40 by awafflar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int				ft_atoi(const char *str)
{
	int			ret;
	int			neg;

	while (ft_isspace(*str))
		str++;
	neg = (*str == '-' ? 1 : 0);
	str += (*str == '-' || *str == '+' ? 1 : 0);
	ret = 0;
	while (ft_isdigit(*str))
		ret = ret * 10 + *(str++) - '0';
	return ((neg ? -ret : ret));
}
