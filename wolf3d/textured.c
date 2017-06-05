/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textured.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brel-baz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/05 19:14:12 by brel-baz          #+#    #+#             */
/*   Updated: 2017/06/05 19:24:13 by brel-baz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int				map_textured(int x, int y)
{
	static int		map[22][22] = {
		{1, 10, 10, 10, 10, 10, 1, 1, 1, 1, 9, 9, 9, 9, 9, 6, 6, 6, 6, 6, 6, 6},
		{9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 9, 0, 0, 0, 0, 0, 9},
		{9, 0, 0, 0, 0, 0, 0, 0, 5, 5, 5, 5, 0, 0, 0, 9, 0, 0, 0, 0, 0, 9},
		{9, 0, 0, 0, 0, 0, 4, 0, 5, 0, 0, 5, 0, 0, 0, 9, 0, 0, 0, 0, 0, 9},
		{9, 0, 0, 0, 0, 0, 1, 0, 5, 0, 0, 5, 0, 0, 0, 9, 0, 0, 0, 0, 0, 9},
		{1, 4, 0, 0, 0, 0, 1, 0, 5, 0, 0, 0, 0, 0, 0, 9, 0, 2, 2, 0, 0, 9},
		{1, 1, 1, 1, 1, 1, 1, 0, 5, 0, 0, 0, 0, 0, 0, 9, 0, 2, 2, 0, 0, 9},
		{1, 1, 1, 1, 1, 1, 1, 0, 5, 5, 5, 5, 0, 0, 0, 9, 0, 0, 0, 0, 0, 9},
		{9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0, 0, 0, 9, 0, 0, 0, 0, 0, 9},
		{9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0, 0, 0, 9, 0, 0, 4, 4, 0, 9},
		{9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0, 0, 0, 0, 0, 0, 4, 4, 0, 9},
		{9, 3, 3, 3, 3, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 9},
		{1, 0, 0, 0, 0, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 9},
		{1, 0, 0, 0, 0, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 9},
		{1, 0, 0, 0, 0, 3, 0, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 10, 10, 10, 10, 1},
		{1, 0, 0, 0, 0, 3, 0, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 10, 0, 0, 0, 9},
		{1, 0, 0, 1, 1, 7, 0, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 10, 0, 0, 0, 9},
		{1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 10, 0, 0, 0, 9},
		{1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 8, 0, 0, 0, 9},
		{1, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 9},
		{1, 0, 0, 0, 3, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 9},
		{1, 1, 1, 1, 3, 3, 3, 3, 3, 3, 3, 3, 3, 5, 2, 2, 2, 2, 2, 2, 2, 1}};

	return (map[x][y]);
}

static void		ray_pos_tex(t_data *data, int x)
{
	data->cam_x = 2 * x / (double)WIDTH - 1;
	data->ray_pos_x = data->pos_x;
	data->ray_pos_y = data->pos_y;
	data->ray_dir_x = data->dir_x + data->plane_x * data->cam_x;
	data->ray_dir_y = data->dir_y + data->plane_y * data->cam_x;
	data->map_x = (int)data->ray_pos_x;
	data->map_y = (int)data->ray_pos_y;
	data->delta_dis_x = sqrt(1 + (data->ray_dir_y * data->ray_dir_y) /
			(data->ray_dir_x * data->ray_dir_x));
	data->delta_dis_y = sqrt(1 + (data->ray_dir_x * data->ray_dir_x) /
			(data->ray_dir_y * data->ray_dir_y));
}

static void		calcul_side_dist_tex(t_data *data)
{
	if (data->ray_dir_x < 0)
	{
		data->step_x = -1;
		data->side_dis_x = (data->ray_pos_x - data->map_x) * data->delta_dis_x;
	}
	else
	{
		data->step_x = 1;
		data->side_dis_x = (data->map_x + 1.0 - data->ray_pos_x) *
			data->delta_dis_x;
	}
	if (data->ray_dir_y < 0)
	{
		data->step_y = -1;
		data->side_dis_y = (data->ray_pos_y - data->map_y) * data->delta_dis_y;
	}
	else
	{
		data->step_y = 1;
		data->side_dis_y = (data->map_y + 1.0 - data->ray_pos_y) *
			data->delta_dis_y;
	}
}

static void		hit_tex(t_data *data)
{
	data->hit = 0;
	while (data->hit == 0)
	{
		if (data->side_dis_x < data->side_dis_y)
		{
			data->side_dis_x += data->delta_dis_x;
			data->map_x += data->step_x;
			data->side = 0;
		}
		else
		{
			data->side_dis_y += data->delta_dis_y;
			data->map_y += data->step_y;
			data->side = 1;
		}
		if (map_textured(data->map_x, data->map_y) > 0)
			data->hit = 1;
	}
}

void			textured(t_data *data)
{
	int		x;

	x = 0;
	while (x < WIDTH)
	{
		ray_pos_tex(data, x);
		calcul_side_dist_tex(data);
		hit_tex(data);
		calc_height_line_tex(data);
		textured_calc_tex(data);
		draw_ceiling_floor(data, x);
		x++;
	}
}
