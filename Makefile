# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ykai-yua <ykai-yua@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/18 22:35:52 by ykai-yua          #+#    #+#              #
#    Updated: 2024/08/19 01:52:09 by ykai-yua         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

SRC = src/main.c\
		src/check_map.c\
		src/destroy.c\
		src/free.c\
		src/ft_keybinds.c\
		src/graphic.c\
		src/init_game.c\
		src/setup_data.c\
		src/check_map_utils.c\

OBJS = $(SRC:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror -Iincludes
MLXFLAGS = -L ./minilibx-linux/ -lmlx -Ilmlx -lXext -lX11

RM = rm -rf

all: $(NAME)
$(NAME): ${OBJS}
	${MAKE} -C ./libft
	${MAKE} -C minilibx-linux/
	$(CC) $(CFLAGS) ${OBJS} ./libft/libft.a minilibx-linux/libmlx.a -Lmlx_linux -lmlx_Linux -Lminilibx-linux/ -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)

clean:
	${RM} ${OBJS}
	${MAKE} -C ./libft fclean
	${RM} minilibx/obj/*.o

fclean: clean
	${RM} $(NAME)
	${MAKE} clean -C minilibx-linux/

re: fclean all

.PHONY: all clean fclean re 