/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awafflar <awafflar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 14:20:27 by awafflar          #+#    #+#             */
/*   Updated: 2019/10/31 11:17:44 by awafflar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_atoi_lite(const char **str)
{
	int		ret;

	ret = 0;
	while (ft_isdigit(**str))
		ret = ret * 10 + *((*str)++) - '0';
	return (ret);
}

char		*ft_ulltostr_base(unsigned long long n, unsigned int base,
				char *digits)
{
	static char		buff[65];
	char			*ret;

	ret = buff + 64;
	*ret = '\0';
	if (n == 0)
		*--ret = digits[0];
	else
		while (n)
		{
			*--ret = digits[n % base];
			n /= base;
		}
	return (ret);
}
