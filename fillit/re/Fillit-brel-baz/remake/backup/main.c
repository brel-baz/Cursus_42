/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brel-baz <brel-baz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 23:52:05 by brel-baz          #+#    #+#             */
/*   Updated: 2017/01/07 07:34:12 by brel-baz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include "fillit.h"

int		main(int argc, char **argv)
{
	(void)argc;
	int		fd;
	int		ret;
	char buff[BUFF_SIZE + 1];
	char *ptr;
	char *str;
	int size;

/*
	Lire
*/

	if (argc != 2)
	{
		write(2, "Usage: ./fillit input_file\n", 27);
		return (0);
	}

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		write(2, "open() failed\n", 14);
		return (0);
	}
	str = ft_memalloc(BUFF_SIZE);
	while ((ret = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[ret] = '\0';
		ptr = ft_strjoin(str, buff);
		free(str);
		str = ptr;
	}
	size = ft_size_map(str);
	printf("%s\n", str);
	if (ft_check_link(str) != 1)
	{
		write(2, "Error\n", 6);
		return (0);
	}
	printf("%d\n", ft_check_link(str));

	//while (ft_solve(ft_convert_alpha(ft_move_tetriminos(ft_tetris_table(str), str), str), str, 0, 0, size) != 1)
		//size++;
	ft_solve(ft_convert_alpha(ft_move_tetriminos(ft_tetris_table(str), str), str), str, 0, 0, size);
	return (0);
}
