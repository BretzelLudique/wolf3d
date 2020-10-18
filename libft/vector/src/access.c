/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   access.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awafflar <awafflar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 15:49:19 by awafflar          #+#    #+#             */
/*   Updated: 2020/01/28 15:49:45 by awafflar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "vector.h"

void			*vector_front(t_vector *vector)
{
	if (vector->size == 0)
		return (NULL);
	return (vector->data);
}

void			*vector_back(t_vector *vector)
{
	if (vector->size == 0)
		return (NULL);
	return ((void *)((char *)vector->data + vector->element_size *
		(vector->size - 1)));
}

int				vector_push_back(t_vector *vector, void *element)
{
	void		*tmp;

	if (!(tmp = vector_new_element(vector)))
		return (-1);
	ft_memcpy(tmp, element, vector->element_size);
	vector_add_element(vector);
	return (0);
}

void			vector_pop_back(t_vector *vector)
{
	if (vector->size != 0)
		vector->size -= 1;
}

void			*vector_at(t_vector *vector, size_t pos)
{
	if (pos >= vector->size)
		return (NULL);
	return ((void *)((char *)vector->data + vector->element_size * pos));
}
