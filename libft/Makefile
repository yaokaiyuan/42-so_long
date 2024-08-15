NAME = libft.a

HEADER = libft.h

SRCS = ft_putstr_fd.c\
		get_next_line.c\
		get_next_line_utils.c\
		ft_itoa.c

OBJS = $(SRCS:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror

%.o: %.c  libft.h
	$(CC) $(CFLAGS) -I libft.h -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS) $(HEADER)
		ar -rcs $(NAME) $(OBJS)

clean:
		rm -rf $(OBJS)

fclean:	clean
		rm -rf $(NAME)

re:		fclean $(NAME)

.PHONY:	all clean fclean re