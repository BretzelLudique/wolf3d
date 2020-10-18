/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awafflar <awafflar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 15:46:32 by awafflar          #+#    #+#             */
/*   Updated: 2020/01/28 15:46:38 by awafflar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double		ft_atof(const char *str)
{
	double	ret;
	char	sign;
	double	fraction;

	ret = 0;
	sign = 0;
	while (ft_isspace(*str))
		str++;
	if (*str == '-')
	{
		str++;
		sign = 1;
	}
	while (ft_isdigit(*str))
		ret = ret * 10. + (double)(*(str++) - '0');
	if (*str == '.' || *str == ',')
	{
		fraction = 0.1;
		while (ft_isdigit(*(++str)))
		{
			ret += fraction * (double)(*str - '0');
			fraction *= 0.1;
		}
	}
	return ((sign ? -ret : ret));
}
