/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brel-baz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/23 01:29:36 by brel-baz          #+#    #+#             */
/*   Updated: 2017/05/26 10:23:26 by brel-baz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	mandelbrot_init(t_dw *dw)
{
	dw->x1 = -1.960;
	dw->x2 = 0.6;
	dw->y1 = -1.2;
	dw->y2 = 1.2;
	dw->i_max = 250;
	dw->zoom_x = 150;
	dw->zoom_y = 150;
	dw->c_r = dw->x / dw->zoom_x + dw->x1;
	dw->c_i = dw->y / dw->zoom_y + dw->y1;
	dw->z_r = 0;
	dw->z_i = 0;
	dw->i = 0;
	dw->image_x = WIDTH;
	dw->image_y = LENGTH;
	dw->color = 0xFFFFFF;
}

void	mandelbrot_init2(t_dw *dw)
{
	dw->c_r = (double)dw->x / dw->zoom_x + dw->x1;
	dw->c_i = (double)dw->y / dw->zoom_y + dw->y1;
	dw->z_r = 0;
	dw->z_i = 0;
	dw->i = 0;
}

void	mandelbrot(t_dw *dw)
{
	dw->x = 0;
	while (dw->x < dw->image_x)
	{
		dw->y = 0;
		while (dw->y < dw->image_y)
		{
			mandelbrot_init2(dw);
			while (dw->z_r * dw->z_r + dw->z_i * dw->z_i < 4 &&
					dw->i < dw->i_max)
			{
				dw->tmp = dw->z_r;
				dw->z_r = dw->z_r * dw->z_r - dw->z_i * dw->z_i + dw->c_r;
				dw->z_i = 2 * dw->z_i * dw->tmp + dw->c_i;
				dw->i++;
			}
			if (dw->i == dw->i_max)
				pixel_put(dw->x, dw->y, dw->color, dw);
			else
				pixel_put(dw->x, dw->y, dw->color * dw->i / dw->i_max, dw);
			dw->y++;
		}
		dw->x++;
	}
}
