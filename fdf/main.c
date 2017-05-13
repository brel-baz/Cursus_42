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

#include "fdf.h"

void	reset(t_draw *dw)
{
	dw->zoom = 5;
	dw->trr = WIDTH / 2;
	dw->trl = LENGTH / 2;
	dw->k = 0;
}

int		key_hook(int key, t_draw *dw)
{
	if (key == ZOOM_UP)
		dw->zoom++;
	if (key == ZOOM_LESS)
		dw->zoom--;
	if (key == RIGHT)
		dw->trr += 5;
	if (key == LEFT)
		dw->trr -= 5;
	if (key == UP)
		dw->trl -= 5;
	if (key == DOWN)
		dw->trl += 5;
	if (key == COLOR)
	{
		if (dw->k == 10)
			dw->k = 0;
		dw->k++;
	}
	if (key == RESET)
		reset(dw);
	if (key == ESC)
		exit(1);
	set_image(dw);
	return (0);
}

int 	main(int ac, char **av)
{
	t_draw *dw;

	if (ac == 2)
	{
		dw = (t_draw*)malloc(sizeof(t_draw));
		dw->str = av[1];
		dw->mlx = mlx_init();
		dw->win = mlx_new_window(dw->mlx, 1300, 1300, "FDF");
		get_point(dw);
		set_image(dw);
		mlx_hook(dw->win, 2, 3, key_hook, dw);
		mlx_loop(dw->mlx);
	}
	else
	{
		ft_putstr("Missed map\n");
		exit(1);
	}
	return (0);
}
