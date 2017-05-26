/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brel-baz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/18 23:22:20 by brel-baz          #+#    #+#             */
/*   Updated: 2017/05/26 01:34:50 by brel-baz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	pixel_put(int x, int y, int color, t_dw *dw)
{
	int index;
	int *ptr;

	if (x >= 0 && x < WIDTH && y >= 0 && y < LENGTH)
	{
		index = y * dw->size_line + x * dw->bpp / 8;
		ptr = (int*)&dw->data[index];
		*ptr = color;
	}
}

void	set_image(t_dw *dw)
{
	dw->img = mlx_new_image(dw->mlx, WIDTH, LENGTH);
	dw->data = mlx_get_data_addr(dw->img, &dw->bpp,
	&dw->size_line, &dw->endian);
	julia(dw);
	mlx_clear_window(dw->mlx, dw->win);
	mlx_put_image_to_window(dw->mlx, dw->win, dw->img, 0, 0);
	mlx_destroy_image(dw->mlx, dw->img);
} 

int		key_hook(int key, t_dw *dw)
{
	if (key == ZOOM_UP)
	{
		dw->zoom_x *= 1.1;
		dw->zoom_y *= 1.1;
		dw->i_max += 5;
	}
	if (key == ZOOM_LESS)
	{
		dw->zoom_x /= 1.1;
		dw->zoom_y /= 1.1;
		dw->i_max -= 5;
	}
	if (key == RIGHT)
		dw->x1 -= 0.1;
	if (key == LEFT)
		dw->x1 += 0.1;
	if (key == UP)
		dw->y1 += 0.1;
	if (key == DOWN)
		dw->y1 -= 0.1;
	if (key == RESET)
		julia_init(dw);
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
	if (key == IN ) 
	{
		dw->zoom_x /= 1.1;
		dw->zoom_y /= 1.1;
	}
	else if (key == OUT )
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

int main(int ac, char **av)
{
	t_dw *dw;
	dw = (t_dw*)malloc(sizeof(t_dw));
	julia_init(dw);
	dw->mlx = mlx_init();
	dw->win = mlx_new_window(dw->mlx, WIDTH, LENGTH, "Fractol");
	set_image(dw);
	mlx_hook(dw->win, 2, 3, key_hook, dw);
	mlx_hook(dw->win, 6, 7, mouse_change, dw);
	mlx_mouse_hook(dw->win, mouse_zoom, dw);
	mlx_loop(dw->mlx);
	return (0);
}
