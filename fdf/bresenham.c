/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brel-baz <brel-baz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/07 00:57:44 by brel-baz          #+#    #+#             */
/*   Updated: 2017/04/16 03:58:31 by brel-baz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "mlx.h"
#include "fdf.h"
#include <math.h>

// void 	put_pixel(t_draw draw, t_point p, int color)
// {
// 	int index;
// 	draw.bpp = 24;
// 	index = draw.size_line * p.x+ (draw.bpp / 8) * p.y;
// 	draw.ptr[index] = (color & 0xFF0000) >> 16;
// 	draw.ptr[index+1] = (color & 0xFF00) >> 8;
// 	draw.ptr[index+2] = (color & 0xFF) ;
// 	int *pointer;
// 	int index;	
// 	if (p.x >= 0 && p.y >= 0 && p.x < 1300 && p.y < 1300)
// 	{
// 		index = draw.size_line * p.y+ (draw.bpp / 8) * p.x;
// 		pointer = (int *)&draw.ptr[index];
// 		*pointer = color;
// 	}
// }


void	line(t_point p0, t_point p1, t_draw draw)
{
	draw.dx = fabs(p1.x - p0.x);
	draw.sx = p0.x < p1.x ? 1 : -1;
	draw.dy = fabs(p1.y - p0.y);
	draw.sy = p0.y < p1.y ? 1 : -1;
	draw.err = (draw.dx > draw.dy ? draw.dx : -draw.dy) / 2;
	draw.e2 = 0;
	while (1)
	{
		mlx_pixel_put(draw.mlx, draw.win, p0.x, p0.y, 0x00C37F);
		if (p0.x == p1.x && p0.y == p1.y)
			break ;
		draw.e2 = draw.err;
		if (draw.e2 > -draw.dx)
		{
			draw.err -= draw.dy;
			p0.x += draw.sx;
		}
		if (draw.e2 < draw.dy)
		{
			draw.err += draw.dx;
			p0.y += draw.sy;
		}
	}
}
