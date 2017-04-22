/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brel-baz <brel-baz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/03 02:05:31 by brel-baz          #+#    #+#             */
/*   Updated: 2017/04/18 00:23:00 by brel-baz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "mlx.h"
#include "fdf.h"

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

t_point		**create_tab(double x, double y, char *file, int i)
{
	t_point	**point;
	char	**tab;
	char	*line;
	int		j;
	int		fd;

	fd = open(file, O_RDONLY);
	i = 0;
	point = (t_point**)malloc(x * sizeof(t_point*));
	while (get_next_line(fd, &line))
	{
		j = 0;
		tab = ft_strsplit(line, ' ');
		point[i] = malloc(y * sizeof(t_point));
		while (tab[j])
		{
			point[i][j].x = i;
			point[i][j].y = j;
			point[i][j].z = ft_atoi(tab[j]);
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
//	void 	put_pixel(t_draw draw, t_point p, int color);
int		main(int ac, char **av)
{
	t_point	**tab;
	t_point p0;
	t_draw draw;
	int i;
	int j;
	double cz;

	p0.length = get_length(av[1]);
	p0.width = get_width(av[1], 0, 0, 0);
	tab = create_tab(p0.length, p0.width, av[1], 0);
	i = 0;
	cz = 1;
	draw.mlx = mlx_init();	
	draw.win = mlx_new_window(draw.mlx, 1300, 1300, "argh");
	while (i < p0.length)
	{
		j = 0;
		while (j < p0.width)
		{
			p0.x = tab[i][j].y;
			p0.y = tab[i][j].x;
			//p0.z = tab[i][j].z;
			tab[i][j].x = p0.x * 2 - p0.y * 2;
			tab[i][j].y = p0.x + p0.y - tab[i][j].z * cz;
			tab[i][j].x *= 3;
			tab[i][j].y *= 3;
			tab[i][j].x += 500;
			tab[i][j].y += 500;
			j++;
		}
		i++;
	}
	i = 0;
	while (i < p0.length - 1)
	{
		j = 0;
		while (j < p0.width - 1)
		{
			line((t_point){tab[i][j].x, tab[i][j].y }, (t_point){ tab[i+1][j].x, tab[i+1][j].y}, draw);
			line((t_point){tab[i][j].x, tab[i][j].y }, (t_point){ tab[i][j+1].x, tab[i][j+1].y}, draw);
			j++;
		}
		i++;
	}
	line((t_point){tab[i][0].x, tab[i][0].y }, (t_point){ tab[i][j].x, tab[i][j].y}, draw);
	line((t_point){tab[0][j].x, tab[0][j].y }, (t_point){ tab[i][j].x, tab[i][j].y}, draw);
	mlx_loop(draw.mlx);
	return (0);
}
