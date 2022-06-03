NAME = libftprintf.a

SRC = ft_printf.c\
      ft_format.c\
      ft_putchar_fd.c\
      ft_putnbr_fd.c\
      ft_putstr_fd.c\

OBJ = $(SRC:.c=.o)

CC = gcc

CFLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -c $(SRC)
	ar cr $(NAME) $(OBJ)

clean:
	rm -rfv $(OBJ)

fclean: clean
	rm -rfv $(NAME)

re: fclean all

norme:
	norminette -R $(SRC)

.PHONY: all clean fclean re norme
