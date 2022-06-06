NAME = so_long

SRC =	src/main.c\
	src/read_image.c\
	src/read_map.c\

INC =	includes/ft_printf/ft_printf.c\
	includes/ft_printf/ft_format.c\
	includes/ft_printf/ft_putchar_fd.c\
	includes/ft_printf/ft_putnbr_fd.c\
	includes/ft_printf/ft_putstr_fd.c\
	includes/get_next_line/get_next_line.c\
	includes/get_next_line/get_next_line_utils.c\
	includes/libft/ft_split.c\

OBJS = $(SRC:.c=.o)

CC = gcc

%.o: %.c
	$(CC) -Wall -Wextra -Werror -I/usr/include -Imlx_linux -O3 -c $< -o $@

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(SRC) $(OBJ) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)

clean:
	rm -rfv $(OBJS)

fclean: clean
	rm -rfv $(NAME)

re: fclean all

.PHONY: all clean fclean re
