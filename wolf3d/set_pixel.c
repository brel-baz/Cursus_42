/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_pixel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brel-baz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/05 19:13:46 by brel-baz          #+#    #+#             */
/*   Updated: 2017/06/05 19:24:02 by brel-baz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int			sky_color(t_data *data, int x, int y)
{
	int		color;
	int		*ptr;

	color = y * data->tex[0].size_line +
		(x * data->tex[0].bpp / 8);
	ptr = (int*)&data->tex[0].pixel[color];
	return (*ptr);
}

void		draw_tex(t_data *data, int x)
{
	int		y;
	int		color;
	int		d;

	y = data->draw_start;
	while (y < data->draw_end)
	{
		d = y * 256 - HEIGHT * 128 + data->line_height * 128;
		data->t_xy = ((d * TEX_H) / data->line_height) / 256;
		color = get_texture_color(data);
		set_pixel(x, y, color, data);
		y++;
	}
}

void		draw_ceiling_floor(t_data *data, int x)
{
	int		y;
	int		color;

	y = 0;
	while (y < data->draw_start)
	{
		color = sky_color(data, x, y);
		set_pixel(x, y, color, data);
		y++;
	}
	draw_tex(data, x);
	y = data->draw_end;
	while (y < HEIGHT)
	{
		set_pixel(x, y, 0x8B9795, data);
		y++;
	}
}

void		set_pixel(int x, int y, int color, t_data *data)
{
	int		index;

	if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
	{
		index = (y * data->size_line) + (x * data->bpp / 8);
		data->pixel[index] = (color & 0xFF);
		data->pixel[index + 1] = (color & 0xFF00) >> 8;
		data->pixel[index + 2] = (color & 0xFF0000) >> 16;
	}
}
