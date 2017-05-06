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

int			check_line(char *str)
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

int			get_length(char *file)
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

int			get_width(char *file, int flag, int check, int x)
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

t_point		**create_tab(double x, double y, char *file, t_draw *dw)
{
	int		fd;
	char	*line;
	t_point	**point;

	fd = open(file, O_RDONLY);
	dw->i = 0;
	point = (t_point**)malloc(x * sizeof(t_point*));
	while (get_next_line(fd, &line))
	{
		dw->j = 0;
		dw->tab = ft_strsplit(line, ' ');
		point[dw->i] = malloc(y * sizeof(t_point));
		while (dw->tab[dw->j])
		{
			point[dw->i][dw->j].x = dw->i;
			point[dw->i][dw->j].y = dw->j;
			point[dw->i][dw->j].z = ft_atoi(dw->tab[dw->j]);
			dw->j++;
		}
		free(line);
		free(dw->tab);
		dw->i++;
	}
	close(fd);
	return (point);
}
