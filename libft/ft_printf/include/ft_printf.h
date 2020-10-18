/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awafflar <awafflar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 09:52:12 by awafflar          #+#    #+#             */
/*   Updated: 2019/09/18 15:03:07 by awafflar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stddef.h>
# include <stdarg.h>

int			ft_printf(const char *format, ...);
int			ft_fdprintf(int fd, const char *format, ...);
int			ft_sprintf(char *str, const char *format, ...);
int			ft_snprintf(char *str, size_t size, const char *format, ...);

int			ft_vprintf(const char *format, va_list ap);
int			ft_vfdprintf(int fd, const char *format, va_list ap);
int			ft_vsprintf(char *str, const char *format, va_list ap);
int			ft_vsnprintf(char *str, size_t size, const char *format,
				va_list ap);

#endif
