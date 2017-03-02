/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brel-baz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 23:52:05 by brel-baz          #+#    #+#             */
/*   Updated: 2017/01/03 14:58:08 by brel-baz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"
#include <fcntl.h>

int		ft_check_link(char *str);
int		ft_size_map(char *str);
//char	*ft_parse_tetri(char *str);
char	**ft_tetris_table(char *str);
int		ft_solve(char **tab, char *str, int x, int y, int size);
char	**ft_move_tetriminos(char **table, char *str);
char	**ft_convert_alpha(char **table, char *str);
char	**ft_map_generator(int size);

int		main(int argc, char **argv)
{
	(void)argc;
	int		fd;
	int		ret;
	char buff[BUFF_SIZE + 1];
	char *ptr;
	char *str;
	int size;

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
	str = ft_memalloc(1);
	while ((ret = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[ret] = '\0';
		ptr = ft_strjoin(str, buff);
		free(str);
		str = ptr;
	}
	size = ft_size_map(str);
//	char str[85] = "..#.\n..#.\n..#.\n..#.\n\n..#.\n.###\n....\n....\n\n....\n.##.\n.##.\n....\n\n....\n.#..\n.#..\n.##.\n";
//	ft_tetris_table(str);
	printf("%s\n", str);
	if (ft_check_link(str) != 1)
	{
		write(2, "Error\n", 6);
		return (0);
	}
//	ft_check_link(argv[1], fd);
	printf("%d\n", ft_check_link(str));
//	printf("%s\n", ft_parse_tetri(str));
//	ft_tetris_table(str);
//	ft_move_tetriminos(ft_tetris_table(str), str);
//	ft_convert_alpha(ft_move_tetriminos(ft_tetris_table(str), str), str);
//	printf("%d\n", ft_size_map(str));
//	ft_map_generator(ft_size_map(str));
//	while (ft_solve(ft_convert_alpha(ft_move_tetriminos(ft_tetris_table(str), str), str), str, 0, 0, size) != 1)
//	{
//		printf("%d\n", size);
//		size++;
//	}
	ft_solve(ft_convert_alpha(ft_move_tetriminos(ft_tetris_table(str), str), str), str, 0, 0, size);
//	printf("%s\n", ft_solve(str));
	return (0);
}
