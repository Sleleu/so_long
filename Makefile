NAME = so_long

SRC =	main.c\

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
