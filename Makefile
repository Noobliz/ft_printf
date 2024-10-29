CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = libftprintf.a
SRC = ft_basics.c ft_printf.c ft_main.c

OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME):$(OBJ)
	ar -rcs $(NAME) $(OBJ)

bonus: $(NAME)
	ar -rcs $(NAME)

%.o:%.c$(NAME)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : re clean fclean all