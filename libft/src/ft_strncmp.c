/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awafflar <awafflar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 16:32:48 by awafflar          #+#    #+#             */
/*   Updated: 2019/10/23 16:38:30 by awafflar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sys/types.h"

int			ft_strncmp(const char *a, const char *b, size_t n)
{
	while (n--)
	{
		if (*a != *b)
			return (*a - *b);
		if (!*a++)
			return (0);
		b++;
	}
	return (0);
}
