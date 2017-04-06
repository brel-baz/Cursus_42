/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brel-baz <brel-baz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/03 02:05:31 by brel-baz          #+#    #+#             */
/*   Updated: 2017/04/07 01:41:00 by brel-baz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fdf.h"
#include "mlx.h"
#define ZOOM 20

int		check_line(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if ((str[i] < '0' || str[i] > '9') && (str[i] != ' '))
			return (-1);
		i++;
	}
	return (1);
}

int		get_length(char *file)
{
	int		x;
	int		fd;
	char	*line;

	x = 0;
	fd = open(file, O_RDONLY);
	if (fd == -1)
		exit(1);
	while (get_next_line(fd, &line))
	{
		if (check_line(line) == 0)
			return (0);
		x++;
		free(line);
	}
	return (x);
}

int		get_width(char *file, int flag, int check)
{
	int		y;
	int		fd;
	char	*line;
	char	**tab;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		exit(1);
	while (get_next_line(fd, &line))
	{
		y = 0;
		tab = ft_strsplit(line, ' ');
		while (tab[y])
			y++;
		if (flag == 0)
		{
			check = y;
			flag = 1;
		}
		free(line);
		free(tab);
		if (y != check)
			return (-1);
	}
	return (y);
}

int		**create_tab(int x, int y, char *file, int i)
{
	int		**point;
	char	**tab;
	char	*line;
	int		j;
	int		fd;

	fd = open(file, O_RDONLY);
	i = 0;
	point = (int**)malloc(x * sizeof(int*));
	while (get_next_line(fd, &line))
	{
		j = 0;
		tab = ft_strsplit(line, ' ');
		point[i] = malloc(y * sizeof(int));
		while (tab[j])
		{
			point[i][j] = ft_atoi(tab[j]);
			j++;
		}
		free(line);
		free(tab);
		i++;
	}
	return (point);
}
int		main(int ac, char **av)
{
	int	**tab;
	int	x;
	int	y;
	int	flag;
	int	check;
	void *mlx;
	void *win;

	flag = 0;
	check = 0;
	ft_putnbr(get_length(av[1]));
	ft_putchar('\n');
	ft_putnbr(get_width(av[1], 0, 0));
	ft_putchar('\n');
	tab = create_tab(get_length(av[1]), get_width(av[1], flag, check), av[1], 0);
	x = 0;
	mlx = mlx_init();
	win = mlx_new_window(mlx, 1300, 1300, "42");
	while (x < get_length(av[1]))
	{
		y = 0;
		while (y < get_width(av[1], flag, check))
		{
			mlx_pixel_put(mlx, win, y * ZOOM, x * ZOOM, 0x00FFFFFF);
			y++;
		}
		x++;
	}
	mlx_loop(mlx);
	return (0);
}
