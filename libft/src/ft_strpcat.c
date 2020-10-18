/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strpcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awafflar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 00:27:47 by awafflar          #+#    #+#             */
/*   Updated: 2019/10/27 00:31:18 by awafflar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_strpcat(char *dest, const char *src)
{
	while (*dest)
		dest++;
	return (ft_strpcpy(dest, src));
}
