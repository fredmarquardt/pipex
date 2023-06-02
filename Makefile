CC = cc
CFLAGS = -Wall -Werror -Wextra
SOURCE = main.c pathfinder.c connect_pipes.c free_stuff.c
OBJ = $(SOURCE:.c=.o)
NAME = pipex
FTPRINTF	= ./ft_printf/libftprintf.a
LIBFT		= ./libft/libft.a

all: $(NAME)

$(NAME):  $(FTPRINTF) $(LIBFT) $(OBJ)
	$(CC) $(SOURCE) $(CFLAGS) $(FTPRINTF) $(LIBFT) -o $(NAME)

$(FTPRINTF):
	@git submodule init ft_printf
	@git submodule update ft_printf
	@cd ft_printf && make && make clean

$(LIBFT):
	@git submodule init libft
	@git submodule update libft
	@cd libft && make && make clean

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean
	$(MAKE) all

.PHONY: all clean fclean re
