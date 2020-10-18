/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fun.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awafflar <awafflar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 15:50:01 by awafflar          #+#    #+#             */
/*   Updated: 2020/01/28 15:50:03 by awafflar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

void			vector_iter(t_vector *vector, void (*fun)(void *))
{
	size_t		i;

	i = 0;
	while (i < vector->size)
		fun(*((void **)vector_at(vector, i++)));
}
