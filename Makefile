NAME = so_long

SRC =	src/main.c\
	src/read_map.c\
	src/error.c\
	src/init_game.c\
	src/game.c\
	src/move.c\
	src/set_textures.c\

INC =	includes/ft_printf/ft_printf.c\
	includes/ft_printf/ft_format.c\
	includes/ft_printf/ft_putchar_fd.c\
	includes/ft_printf/ft_putnbr_fd.c\
	includes/ft_printf/ft_putstr_fd.c\
	includes/get_next_line/get_next_line.c\
	includes/get_next_line/get_next_line_utils.c\
	includes/ft_split.c\
	includes/ft_calloc.c\
	includes/ft_bzero.c\

OBJS = $(SRC:.c=.o)

CC = gcc

%.o: %.c
	$(CC) -Wall -Wextra -Werror -I/usr/include -Imlx_linux -O3 -c $< -o $@

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(SRC) $(INC) $(OBJ) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)

clean:
	rm -rfv $(OBJS)

fclean: clean
	rm -rfv $(NAME)

re: fclean all

norme:
	@echo "\033[35;36m\n\n === INCLUDES FILES === \n\n"
	norminette includes/*
	@echo "\033[35;32m\n\n === FILES OF SO_LONG === \n\n"
	norminette src/*

.PHONY: all clean fclean re
