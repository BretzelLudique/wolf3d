# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: czhang <czhang@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/06/21 16:37:29 by czhang            #+#    #+#              #
#    Updated: 2020/06/21 16:37:31 by czhang           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= wolf3d

CC		= gcc

RM		= /bin/rm

CFLAGS	= -Wall -Wextra -Werror -pedantic

LIB_FT	= -L libft/ -lft -lm

LIB_MLX	= -L /usr/X11/lib -L minilibx-linux -lmlx -lXext -lX11

FILES	= 	main.c				\
			getdata.c			\
			error.c				\
			init_mlx.c			\
			misc.c				\
			draw.c				\
			trace.c				\
			lines_blocks.c		\
			move.c				\
			raycasting.c		\
			color.c				\
			get_next_line.c

SRCS	= $(addprefix src/, $(FILES))

OBJS	= $(SRCS:src/%.c=.obj/%.o)

INC		= -I includes -I libft/includes

INC_MLX = -I /usr/X11/include

all: $(NAME)

$(NAME): lib_comp create_folder_object $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) -O3 $(INC) $(INC_MLX) $(LIB_FT) $(LIB_MLX)

.obj/%.o: src/%.c
	$(CC) -c $< -o $@ $(CFLAGS) $(INC) $(INC_MLX)
	@echo "\033[34m$(CC) -o \033[4m$@\033[0m\033[34m -c $< $(CFLAGS) \
	$(LDFLAGS)\033[0m"

lib_comp:
	@echo "Compilation de la libft..."
	make -C libft
	@echo "Compilation de la mlx..."
	make -C minilibx-linux

create_folder_object:
	/bin/mkdir -p .obj

clean:
	@$(RM) -rf .obj
	make -C libft/ clean
	make -C minilibx-linux clean
	@echo "\033[31m$(RM) -rf \033[0m\033[41m.obj\033[0m"

fclean: clean
	@$(RM) -f $(NAME)
	make -C libft/ fclean
	@echo "\033[31m$(RM) -f \033[0m\033[41m$(NAME)\033[0m"

re: fclean all

.PHONY: all lib_comp create_folder_object clean fclean re
