/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czhang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 01:53:17 by czhang            #+#    #+#             */
/*   Updated: 2020/06/15 20:39:11 by czhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static char		*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*str;
	int		i;

	if (!s)
		return (NULL);
	if (!(str = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	i = 0;
	while (len--)
		str[i++] = *(s + start++);
	str[i] = 0;
	return (str);
}

static void		*ptitfree(char **tab, unsigned int j)
{
	while (j)
		ft_memdel((void **)&tab[j-- - 1]);
	return (NULL);
}

char			**ft_strsplit(char const *s, char c)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	len_word;
	char			**tab;

	if (!s || !(tab = (char**)malloc(sizeof(char*) * (ft_cntwrd(s, c) + 1))))
		return (NULL);
	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		len_word = 0;
		if (s[i] && s[i] != c)
		{
			while (s[i + len_word] && s[i + len_word] != c)
				len_word++;
			if (!(tab[j++] = ft_strsub(s, i, len_word)))
				ptitfree(tab, j);
			i += len_word;
		}
	}
	tab[j] = 0;
	return (tab);
}
