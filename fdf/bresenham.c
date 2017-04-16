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
#define ZOOM 10

void	line(t_point p0, t_point p1, t_draw draw)
{
	draw.dx = abs(p1.x - p0.x);
	draw.sx = p0.x < p1.x ? 1 : -1;
	draw.dy = abs(p1.y - p0.y);
	draw.sy = p0.y < p1.y ? 1 : -1;
	draw.err = (draw.dx > draw.dy ? draw.dx : -draw.dy) / 2;
	draw.e2 = 0;
	while (1)
	{
		mlx_pixel_put(draw.mlx, draw.win, p0.x, p0.y, 0x26C4EC);
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
