/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brel-baz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/26 09:43:54 by brel-baz          #+#    #+#             */
/*   Updated: 2017/05/26 10:19:34 by brel-baz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		key_hook(int key, t_dw *dw)
{
	if (key == FRACTALE)
	{
		if (dw->fract == 5)
			dw->fract = 1;
		else
			dw->fract++;
		fractal_init(dw);
	}
	if (key == COLOR)
		dw->i_max += 5;
	if (key == RIGHT)
		dw->x1 -= 0.1;
	if (key == LEFT)
		dw->x1 += 0.1;
	if (key == UP)
		dw->y1 += 0.1;
	if (key == DOWN)
		dw->y1 -= 0.1;
	if (key == RESET)
		fractal_init(dw);
	if (key == ESC)
		exit(1);
	set_image(dw);
	return (0);
}

int		mouse_zoom(int key, int x, int y, t_dw *dw)
{
	double tmpx;
	double tmpy;

	tmpx = x / dw->zoom_x + dw->x1;
	tmpy = y / dw->zoom_y + dw->y1;
	if (key == IN)
	{
		dw->zoom_x /= 1.1;
		dw->zoom_y /= 1.1;
	}
	else if (key == OUT)
	{
		dw->zoom_x *= 1.1;
		dw->zoom_y *= 1.1;
	}
	dw->x1 = tmpx - (x / dw->zoom_x);
	dw->y1 = tmpy - (y / dw->zoom_y);
	set_image(dw);
	return (0);
}

int		mouse_change(int x, int y, t_dw *dw)
{
	if (x < WIDTH && x > 0 && y < LENGTH && y > 0)
	{
		dw->c_r = (double)(x + 400 - WIDTH) / 500;
		dw->c_i = (double)(y + 400 - LENGTH) / 500;
	}
	set_image(dw);
	return (0);
}
