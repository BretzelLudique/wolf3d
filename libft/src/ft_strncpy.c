/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awafflar <awafflar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 01:47:15 by awafflar          #+#    #+#             */
/*   Updated: 2019/10/24 01:53:56 by awafflar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>

char			*ft_strncpy(char *dest, const char *src, size_t n)
{
	char		*ret;

	ret = dest;
	while (n > 0 && *src)
	{
		*ret = *src;
		ret++;
		src++;
		n--;
	}
	while (n > 0)
	{
		*ret = '\0';
		n--;
	}
	return (ret);
}
