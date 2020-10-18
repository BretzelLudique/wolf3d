/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cntwrd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czhang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 02:05:50 by czhang            #+#    #+#             */
/*   Updated: 2020/06/21 16:35:22 by czhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

size_t	ft_cntwrd(char const *s, char sep)
{
	size_t	n;
	size_t	is_word;

	n = 0;
	while (*s && is_word)
	{
		is_word = 0;
		while (*s && *s == sep)
			s++;
		while (*s && *s != sep)
		{
			s++;
			is_word = 1;
		}
		n += is_word;
		if (!is_word && *s)
			s++;
	}
	return (n);
}
