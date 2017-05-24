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

// void	mandelbrot_init(t_dw *dw)
// {
// 	dw->i_max = 50;
// 	dw->zoom = 300;
// 	dw->x1 = -2.1;
// 	dw->y1 = -1.2;
// 	dw->color = 0xFFFFFF;
// }

void	fractol(t_dw *dw)
{
	// on définit la zone que l'on dessine. Ici, la fractale en entière
	dw->x1 = -2.1;
	dw->x2 = 0.6;
	dw->y1 = -1.2;
	dw->y2 = 1.2;
	// dw->zoom = 100; // pour une distance de 1 sur le plan, on a 100 pixel sur l'image
	dw->i_max = 50;
	dw->x = 0;
	dw->c_r = dw->x / dw->zoom + dw->x1;
    dw->c_i = dw->y / dw->zoom + dw->y1;
    dw->z_r = 0;
    dw->z_i = 0;
    dw->i = 0;
    dw->image_x = 370;
    dw->image_y = 340;
    dw->color = 0xFFFFFF;

	// on calcule la taille de l'image :
	dw->zoom_x = dw->image_x / (dw->x2 - dw->x1);
	dw->zoom_y = dw->image_y / (dw->y2 - dw->y1);

	while (dw->x < dw->image_x)
	{
		dw->y = 0;
	    while (dw->y < dw->image_y)
	    {
	    	dw->c_r = dw->x / dw->zoom_x + dw->x1;
       		dw->c_i = dw->y / dw->zoom_y + dw->y1;
       		dw->z_r = 0;
       		dw->z_i = 0;
       		dw->i = 0;
    		while (dw->z_r * dw->z_r + dw->z_i * dw->z_i < 4 && dw->i < dw->i_max)
	    	{
	            dw->tmp = dw->z_r;
	            dw->z_r = dw->z_r * dw->z_r - dw->z_i * dw->z_i + dw->c_r;
	            dw->z_i = 2 * dw->z_i * dw->tmp + dw->c_i;
	            dw->i = dw->i + 1;
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

void	set_image(t_dw *dw)
{
	dw->img = mlx_new_image(dw->mlx, 370, 340);
	dw->data = mlx_get_data_addr(dw->img, &dw->bpp,
	&dw->size_line, &dw->endian);
	fractol(dw);
	mlx_clear_window(dw->mlx, dw->win);
	mlx_put_image_to_window(dw->mlx, dw->win, dw->img, 0, 0);
	mlx_destroy_image(dw->mlx, dw->img);
} 

int main(void)
{
	t_dw *dw;
	dw = (t_dw*)malloc(sizeof(t_dw));
	dw->mlx = mlx_init();
	dw->win = mlx_new_window(dw->mlx, 370, 340, "Fractol");
	set_image(dw);
	// mlx_hook(dw->win, 2, 3, key_hook, dw);
	mlx_loop(dw->mlx);
	return (0);
}
