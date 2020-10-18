/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awafflar <awafflar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 15:47:11 by awafflar          #+#    #+#             */
/*   Updated: 2020/01/28 15:47:13 by awafflar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "libft.h"

char		*ft_strjoin(const char *a, const char *b)
{
	char	*ret;

	if (!(ret = (char *)malloc(sizeof(char) *
			(ft_strlen(a) + ft_strlen(b) + 1))))
		return (NULL);
	ft_strcpy(ft_strpcpy(ret, a), b);
	return (ret);
}
