# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jreszka <jreszka@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/06 09:54:38 by jreszka           #+#    #+#              #
#    Updated: 2017/01/12 21:40:38 by jreszka          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

CC = gcc

FLAGS = -Wall -Wextra -Werror

SRC = main.c \
	get_buf.c \
	parse.c \
	num_are_valid.c \
	hash_neighbours_are_valid.c \
	ft_print_2d_table.c \
	ft_int_sqrt.c \
	ft_init_map.c \
	ft_build_tets.c \
	ft_tets_ref_points.c \
	ft_tets_chars.c \
	ft_solve.c \
	make_map_bigger.c \
	ft_check_tet_place.c \
	rm_and_move.c \

OBJ = $(SRC:.c=.o)

$(NAME): $(OBJ)
	@make -C ./libft
	$(CC) $(FLAGS) -o $(NAME) -lft -L./libft -I./libft $(OBJ)

all: $(NAME)

clean:
	make -C ./libft clean
	rm -rf $(OBJ)

fclean : clean
	make -C ./libft fclean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
