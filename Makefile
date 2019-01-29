NAME = fillit

SRC = *.c

HEADER = *.h

FLAGS = -Wall -Wextra -Werror -g

all:
	@gcc $(FLAGS) $(SRC) -o $(NAME) -I libft -L libft/ -lft

clean:
	@/bin/rm -f *.o

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all./
