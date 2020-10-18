/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strpcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awafflar <awafflar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 17:49:43 by awafflar          #+#    #+#             */
/*   Updated: 2019/10/22 17:52:15 by awafflar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char				*ft_strpcpy(char *dest, const char *src)
{
	while ((*dest = *src))
	{
		dest++;
		src++;
	}
	return (dest);
}
