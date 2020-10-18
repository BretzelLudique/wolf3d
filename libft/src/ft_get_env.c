/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awafflar <awafflar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 16:40:31 by awafflar          #+#    #+#             */
/*   Updated: 2019/10/23 16:57:09 by awafflar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

#include "libft.h"

char			*ft_get_env(char *name, char **env)
{
	size_t		size;

	size = 0;
	while (name[size] != '\0' && name[size] != '=')
		size++;
	while (*env)
	{
		if (ft_strncmp(*env, name, size) == 0 && (*env)[size] == '=')
			return (*env + size + 1);
		env++;
	}
	return (NULL);
}
