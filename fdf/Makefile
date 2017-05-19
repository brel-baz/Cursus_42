# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: brel-baz <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/05/15 04:11:59 by brel-baz          #+#    #+#              #
#    Updated: 2017/05/15 04:12:04 by brel-baz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = fdf
PATH_SRC = ./
PATH_OBJ = ./
PATH_INC = ./libft

CC = gcc
CFLAGS = -Wall -Wextra -Werror

HEAD = fdf.h

SRC =	main.c \
		draw.c \
		bresenham.c \
		color.c \
		create_tab.c \

OBJ = $(patsubst %.c,%.o,$(addprefix $(PATH_SRC), $(SRC)))


all: $(NAME)

$(NAME): $(OBJ) $(HEAD)
	make -C libft/
	$(CC) $(CFLAGS) -I $(PATH_INC) -c $(SRC)
	$(CC) -o $(NAME) $(OBJ) -lm -L libft/ -lft -lmlx -framework OpenGL -framework AppKit

clean:
	make -C libft/ clean
	/bin/rm -f $(OBJ)

fclean: clean
	make -C libft/ fclean
	/bin/rm -f $(NAME)

re: fclean all

.PHONY: clean fclean