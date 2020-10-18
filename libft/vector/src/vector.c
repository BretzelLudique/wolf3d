/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awafflar <awafflar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 15:50:08 by awafflar          #+#    #+#             */
/*   Updated: 2020/01/28 15:50:24 by awafflar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "libft.h"
#include "vector.h"

t_vector	*vector_create(size_t element_size, size_t capacity)
{
	t_vector	*ret;

	if (!(ret = (t_vector *)malloc(sizeof(t_vector))))
		return (NULL);
	if (vector_init(ret, element_size, capacity))
	{
		free(ret);
		return (NULL);
	}
	return (ret);
}

int			vector_init(t_vector *vector, size_t element_size, size_t capacity)
{
	if (!(vector->data = malloc(element_size * capacity)))
		return (-1);
	vector->capacity = capacity;
	vector->element_size = element_size;
	vector->size = 0;
	return (0);
}

void		*vector_new_element(t_vector *vector)
{
	void	*tmp;

	if (vector->size == vector->capacity)
	{
		vector->capacity *= 2;
		if (!(tmp = malloc(vector->element_size * vector->capacity)))
			return (NULL);
		ft_memcpy(tmp, vector->data, vector->element_size * vector->size);
		free(vector->data);
		vector->data = tmp;
	}
	return ((void *)((char *)vector->data + vector->element_size *
		vector->size));
}

void		vector_add_element(t_vector *vector)
{
	vector->size += 1;
}

void		vector_destroy(t_vector *vector)
{
	free(vector->data);
	vector->data = NULL;
	vector->size = 0;
	vector->capacity = 0;
}
