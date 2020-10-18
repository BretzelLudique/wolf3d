/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awafflar <awafflar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 17:30:58 by awafflar          #+#    #+#             */
/*   Updated: 2020/06/15 20:40:17 by czhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <sys/types.h>
# include <unistd.h>

# include "../ft_printf/include/ft_printf.h"

char					*ft_get_env(char *name, char **env);

char					*ft_itoa(int n);
char					*ft_lltostr(long long n);
char					*ft_ulltostr(unsigned long long n);

int						ft_atoi(const char *str);
double					ft_atof(const char *str);

int						ft_isprint(const char c);
int						ft_isspace(const char c);
int						ft_isdigit(const char c);

void					*ft_memcpy(void *dest, const void *src, size_t len);

size_t					ft_strlen(const char *str);

char					*ft_strcpy(char *dest, const char *src);
char					*ft_strncpy(char *dest, const char *src, size_t n);
char					*ft_strpcpy(char *dest, const char *src);

char					*ft_strcat(char *dest, const char *src);
char					*ft_strpcat(char *dest, const char *src);

int						ft_strcmp(const char *a, const char *b);
int						ft_strncmp(const char *a, const char *b, size_t n);

char					*ft_strchr(const char *s, int c);

char					*ft_strdup(const char *s);
char					*ft_strjoin(const char *a, const char *b);
char					**ft_strsplit(const char *s, char delim);

int						ft_putchar(int c);
void					ft_putnbr(int n);
ssize_t					ft_putstr(char const *s);
void					*ft_memset(void *str, int c, size_t len);
void					ft_putendl(char const *s);
void					*ft_bzero(void *truc, size_t size);
void					*ft_memalloc(size_t size);
void					ft_memdel(void **ap);

size_t					ft_cntwrd(char const *s, char c);
#endif
