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

void	pixel_put(int x, int y, int color, t_draw *dw)
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

void	line(t_point p0, t_point p1, t_draw *dw)
{
	dw->dx = fabs(p1.x - p0.x);
	dw->sx = p0.x < p1.x ? 1 : -1;
	dw->dy = fabs(p1.y - p0.y);
	dw->sy = p0.y < p1.y ? 1 : -1;
	dw->err = (dw->dx > dw->dy ? dw->dx : -dw->dy) / 2;
	dw->e2 = 0.0;
	while (1)
	{
		pixel_put(p0.x, p0.y, BLUE, dw);
		if (p0.x == p1.x && p0.y == p1.y)
			break ;
		dw->e2 = dw->err;
		if (dw->e2 > -dw->dx)
		{
			dw->err -= dw->dy;
			p0.x += dw->sx;
		}
		if (dw->e2 < dw->dy)
		{
			dw->err += dw->dx;
			p0.y += dw->sy;
		}
	}
}
