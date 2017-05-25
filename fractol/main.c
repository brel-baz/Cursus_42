/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brel-baz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/18 23:22:20 by brel-baz          #+#    #+#             */
/*   Updated: 2017/05/18 23:23:02 by brel-baz         ###   ########.fr       */
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
	mandelbrot(dw);
	mlx_clear_window(dw->mlx, dw->win);
	mlx_put_image_to_window(dw->mlx, dw->win, dw->img, 0, 0);
	mlx_destroy_image(dw->mlx, dw->img);
} 

int		key_hook(int key, t_dw *dw)
{
	// if (key == ZOOM_UP)
	// {
	// 	dw->zoom_x++;
	// 	dw->zoom_y++;
	// }
	// if (key == ZOOM_LESS && dw->zoom > 1)
	// 	dw->zoom--;
	// if (key == RIGHT)
	// 	dw->trr += 5;
	// if (key == LEFT)
	// 	dw->trr -= 5;
	// if (key == UP)
	// 	dw->trl -= 5;
	// if (key == DOWN)
	// 	dw->trl += 5;
	// if (key == COLOR)
	// {
	// 	if (dw->k == 10)
	// 		dw->k = -1;
	// 	dw->k++;
	// }
	// if (key == RESET)
	// 	reset(dw);
	if (key == ESC)
		exit(1);
	set_image(dw);
	return (0);
}

int main(int ac, char **av)
{
	t_dw *dw;
	dw = (t_dw*)malloc(sizeof(t_dw));
	dw->mlx = mlx_init();
	dw->win = mlx_new_window(dw->mlx, WIDTH, LENGTH, "Fractol");
	set_image(dw);
	mlx_hook(dw->win, 2, 3, key_hook, dw);
	mlx_loop(dw->mlx);
	return (0);
}
