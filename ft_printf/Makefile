# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: brel-baz <brel-baz@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/05/26 10:29:59 by brel-baz          #+#    #+#              #
#    Updated: 2017/08/25 08:16:13 by brel-baz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = clang
HEADER = ./ft_printf.h
FLAG = -Wall -Wextra -Werror -O3
OPTION = -c -I $(HEADER)
SRC = ./ft_printf.c ./ft_convert.c ./ft_flag.c ./ft_itoa_base.c ./ft_itoa_base_up.c ./ft_utoa.c

OBJ = $(addsuffix .o,$(basename $(SRC)))

.PHONY : all clean fclean re

all : $(NAME)

$(NAME) : $(OBJ)
		make -C libft/
		cp libft/libft.a ./$(NAME)
		ar rc $(NAME) $(OBJ)
		ranlib $(NAME)

%.o : %.c
	$(CC) $(FLAG) $(OPTION) -c $< -o $@

clean :
		make -C libft/ clean
		rm -f $(OBJ)
fclean : clean
		make -C libft/ fclean
		rm -f $(NAME)

re : fclean all re
