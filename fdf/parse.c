/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brel-baz <brel-baz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/03 02:05:31 by brel-baz          #+#    #+#             */
/*   Updated: 2017/04/16 04:46:12 by brel-baz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "mlx.h"
#include "fdf.h"
#define ZOOM 27

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
	int		y;
	int		fd;
	char	*line;

	y = 0;
	fd = open(file, O_RDONLY);
	if (fd == -1)
		exit(1);
	while (get_next_line(fd, &line))
	{
		if (check_line(line) == -1)
			return (-1);
		y++;
		free(line);
	}
	close(fd);
	return (y);
}

int		get_width(char *file, int flag, int check, int x)
{
	int		fd;
	char	*line;
	char	**tab;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		exit(1);
	while (get_next_line(fd, &line))
	{
		x = 0;
		tab = ft_strsplit(line, ' ');
		while (tab[x])
			x++;
		if (flag == 0)
		{
			check = x;
			flag = 1;
		}
		free(line);
		free(tab);
		if (x != check)
			return (-1);
	}
	close(fd);
	return (x);
}

int		**create_tab(int x, int y, char *file, int i)
{
	int	**point;
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
	close(fd);
	return (point);
}

void	line(t_point p0, t_point p1, t_draw draw);

int		main(int ac, char **av)
{
	int	**tab;
	int length = get_length(av[1]);
	int width = get_width(av[1], 0, 0, 0);
	t_draw draw;
	t_point p0;
	t_point p1;

	// ft_putnbr(get_length(av[1]));
	// ft_putchar('\n');
	// ft_putnbr(get_width(av[1], 0, 0, 0));
	// ft_putchar('\n');
	if (ac == 2)
	{
		if (!av[1])
			return (0);
		if (get_length(av[1]) == -1 || get_width(av[1], 0, 0, 0) == -1)
		{
			ft_putstr("Wrong map\n");
			exit (1);
		}
		tab = create_tab(length, width, av[1], 0);
		p0.x = 0;
		p0.y = 0;
		draw.mlx = mlx_init();
		draw.win = mlx_new_window(draw.mlx, 1300, 1300, "42");
		while (p0.y < length - 1)
		{
			p0.x = 0;
			while (p0.x < width - 1)
			{
				p1.x = (p0.x + 1);
				p1.y = (p0.y);
				line((t_point){p0.x * ZOOM, p0.y *ZOOM}, (t_point){ p1.x * ZOOM, p1.y * ZOOM }, draw);
				p1.x = p0.x;
				p1.y = (p0.y + 1);
				line((t_point){p0.x * ZOOM, p0.y *ZOOM}, (t_point){ p1.x * ZOOM, p1.y * ZOOM }, draw);
				p0.x++;
			}
			p0.y++;
		 }
		p1.x++;
		line((t_point){0 * ZOOM, p0.y *ZOOM}, (t_point){ p1.x * ZOOM, p1.y * ZOOM }, draw);
		line((t_point){p0.x * ZOOM, 0 *ZOOM}, (t_point){ p1.x * ZOOM, p1.y * ZOOM }, draw);
		mlx_loop(draw.mlx);
	}
	return (0);
}
