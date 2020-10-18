/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awafflar <awafflar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 15:50:47 by awafflar          #+#    #+#             */
/*   Updated: 2020/01/28 15:50:58 by awafflar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H

# include <stddef.h>

typedef struct	s_vector
{
	size_t		capacity;
	void		*data;
	size_t		size;
	size_t		element_size;
}				t_vector;

t_vector		*vector_create(size_t element_size, size_t capacity);
int				vector_init(t_vector *vector, size_t element_size,
					size_t capacity);
void			*vector_new_element(t_vector *vector);
void			vector_add_element(t_vector *vector);
void			vector_destroy(t_vector *vector);

void			*vector_front(t_vector *vector);
void			*vector_back(t_vector *vector);
int				vector_push_back(t_vector *vector, void *element);
void			vector_pop_back(t_vector *vector);
void			*vector_at(t_vector *vector, size_t pos);

void			vector_iter(t_vector *vector, void (*fun)(void *));

#endif
