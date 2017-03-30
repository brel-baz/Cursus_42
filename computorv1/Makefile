# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: brel-baz <brel-baz@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/07 23:18:21 by brel-baz          #+#    #+#              #
#    Updated: 2017/03/01 16:49:13 by brel-baz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = computorv1

CC = gcc

FLAGS = -Wall -Wextra -Werror

SRC = main.c 		

OBJ = $(SRC:.c=.o)

$(NAME): $(OBJ)
	make -C libft/ fclean && make -C libft/
	$(CC) -o $(NAME) $(FLAGS) $(OBJ) -I libft/includes -L libft/ -lft

all: $(NAME)

clean:
	make -C ./libft clean
	rm -rf $(OBJ)

fclean : clean
	make -C ./libft fclean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re