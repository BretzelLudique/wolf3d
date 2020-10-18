# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: awafflar <awafflar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/18 09:38:44 by awafflar          #+#    #+#              #
#    Updated: 2020/06/15 15:35:48 by czhang           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

FLAGS = -Wall -Wextra -Wconversion -Werror -O3

CC = gcc $(FLAGS)

INC = -Iinclude -Ift_printf/include -Ivector/include

SRC = 			ft_atof.c				\
				ft_atoi.c				\
				ft_get_env.c			\
				ft_isdigit.c			\
				ft_isprint.c			\
				ft_isspace.c			\
				ft_itoa.c				\
				ft_lltostr.c			\
				ft_cntwrd.c				\
				ft_memcpy.c				\
				ft_putchar.c			\
				ft_strcat.c				\
				ft_strchr.c				\
				ft_strcmp.c				\
				ft_strcpy.c				\
				ft_strdup.c				\
				ft_strjoin.c			\
				ft_strlen.c				\
				ft_strncmp.c			\
				ft_strncpy.c			\
				ft_strpcat.c			\
				ft_strpcpy.c			\
				ft_strsplit.c			\
				ft_ulltostr.c			\
				ft_putnbr.c\
				ft_putstr.c\
				ft_putendl.c\
				ft_memset.c\
				ft_bzero.c\
				ft_memalloc.c\
				ft_memdel.c\

SRC_PRINTF =	ft_printf.c 			\
				buffer.c				\
				buffer_add.c			\
				conversion.c			\
				di_tostring.c			\
				double_exception.c		\
				f_tostring.c			\
				fields.c				\
				ft_dtoa.c				\
				ft_ldtoa.c				\
				ft_vprintf.c			\
				parse.c					\
				parse_star.c			\
				print.c					\
				printf_core.c			\
				print_binary.c			\
				print_char.c			\
				print_decimal.c			\
				print_float.c			\
				print_hexa.c			\
				print_modulo.c			\
				print_n.c				\
				print_octal.c			\
				print_pointer.c			\
				print_string.c			\
				print_unsigned.c		\
				utils.c					\
				get_args_misc.c			\
				get_args_signed.c		\
				get_args_unsigned.c		\
				oux_tostring.c			\
				total_to_ptr.c

SRC_VECTOR =	access.c				\
				fun.c					\
				vector.c

OBJ = $(SRC:%.c=obj/%.o)

OBJ_PRINTF =  $(SRC_PRINTF:%.c=ft_printf/obj/%.o)

OBJ_VECTOR = $(SRC_VECTOR:%.c=vector/obj/%.o)

RM = rm -f

all: $(NAME)

$(NAME): $(OBJ) $(OBJ_PRINTF) $(OBJ_VECTOR)
	ar rc $@ $^
	ranlib $@

obj/%.o: src/%.c
	@mkdir -p obj/
	$(CC) $(INC) -c -o $@ $<

ft_printf/obj/%.o: ft_printf/src/%.c
	@mkdir -p ft_printf/obj
	$(CC) $(INC) -c -o $@ $<

vector/obj/%.o: vector/src/%.c
	@mkdir -p vector/obj
	$(CC) $(INC) -c -o $@ $<

clean:
	$(RM) $(OBJ)
	$(RM) $(OBJ_PRINTF)
	$(RM) $(OBJ_VECTOR)

fclean: clean
	$(RM) $(NAME)
	rm -rf obj
	rm -rf ft_printf/obj
	rm -rf vector/obj

re: fclean all

.PHONY: all clean fclean re
