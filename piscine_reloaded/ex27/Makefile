# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: brel-baz <brel-baz@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/07 23:18:21 by brel-baz          #+#    #+#              #
#    Updated: 2016/11/08 00:41:13 by brel-baz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_display_file

SRC = srcs/ft_putchar.c\
	  srcs/ft_putstr.c\
	  srcs/ft_display_file.c\
	  srcs/main.c\

FLAG = -Wall -Werror -Wextra

OBJ = ft_putchar.o\
	  ft_putstr.o\
	  ft_display_file.o\
	  main.o\

all :
	gcc $(FLAG) $(SRC) -c
	gcc $(FLAG) $(SRC) -o $(NAME)

clean :
	rm -rf $(OBJ)

fclean : clean
	rm -rf $(NAME)

re : fclean all
