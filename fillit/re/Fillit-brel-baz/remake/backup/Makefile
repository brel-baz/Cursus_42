# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: brel-baz <brel-baz@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/07 23:18:21 by brel-baz          #+#    #+#              #
#    Updated: 2017/01/07 07:59:09 by brel-baz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

CC = gcc

FLAGS = -Wall -Werror -Wextra -g -fsanitize=address

SRC = main.c ft_size_map.c ft_check_link.c ft_tetris_table.c \
	ft_solve.c ft_move_tetriminos.c ft_map_generator.c \
	ft_check_high.c ft_check_left.c ft_check_solve.c ft_convert_alpha.c \
	ft_count_hash.c ft_decalage.c ft_get_char.c ft_move_high.c ft_move_left.c \
	ft_move_right.c ft_move_bottom.c ft_check_bottom.c ft_check_right.c \
	libft.a

$(NAME): 
	$(CC) $(FLAGS) $(SRC)
