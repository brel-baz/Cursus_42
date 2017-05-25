/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buddhabrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brel-baz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/24 12:15:39 by brel-baz          #+#    #+#             */
/*   Updated: 2017/05/24 12:15:45 by brel-baz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	buddhabrot_init(t_dw *dw)
{
	dw->x1 = -2.1;
	dw->x2 = 0.6;
	dw->y1 = -1.2;
	dw->y2 = 1.2;
	dw->i_max = 	500;
	dw->x = 0;
	dw->c_r = dw->x / dw->zoom + dw->x1;
    dw->c_i = dw->y / dw->zoom + dw->y1;
    dw->z_r = 0;
    dw->z_i = 0;
    dw->i = 0;
    dw->image_x = WIDTH;
    dw->image_y = LENGTH;
    dw->color = 0xFFFFFF;
	dw->zoom_x = dw->image_x / (dw->x2 - dw->x1);
	dw->zoom_y = dw->image_y / (dw->y2 - dw->y1);
}

void	buddhabrot_init2(t_dw *dw)
{
	dw->c_r = dw->x / dw->zoom_x + dw->x1;
    dw->c_i = dw->y / dw->zoom_y + dw->y1;
    dw->z_r = 0.123;
    dw->z_i = 0.745;
    dw->i = 0;
}

void	buddhabrot(t_dw *dw)
{
	while (dw->x < dw->image_x)
	{
		dw->y = 0;
	    while (dw->y < dw->image_y)
	    {
	    	buddhabrot_init2(dw);
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
