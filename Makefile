# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hirenpat <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/15 21:51:44 by hirenpat          #+#    #+#              #
#    Updated: 2019/02/15 21:52:39 by hirenpat         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRC = src/*.c

HEADER = inc/*.h

FLAGS = -Wall -Wextra -Werror

all: $(NAME)
$(NAME):
	@gcc $(FLAGS) $(SRC) -o $(NAME)

clean:
	@/bin/rm -f *.o

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all
