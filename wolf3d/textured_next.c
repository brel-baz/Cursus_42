/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textured_next.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brel-baz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/05 19:14:50 by brel-baz          #+#    #+#             */
/*   Updated: 2017/06/05 19:24:36 by brel-baz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void		calc_height_line_tex(t_data *data)
{
	data->perp_wall_dis = (data->side == 0) ? (data->map_x - data->ray_pos_x +
			(1 - data->step_x) / 2) / data->ray_dir_x : (data->map_y -
				data->ray_pos_y + (1 - data->step_y) / 2) / data->ray_dir_y;
	data->line_height = (int)(HEIGHT / data->perp_wall_dis);
	data->draw_start = HEIGHT / 2 - data->line_height / 2;
	if (data->draw_start < 0)
		data->draw_start = 0;
	data->draw_end = HEIGHT / 2 + data->line_height / 2;
	if (data->draw_end >= HEIGHT)
		data->draw_end = HEIGHT - 1;
}

void		textured_calc_tex(t_data *data)
{
	data->tex_n = map_textured(data->map_x, data->map_y) != 0 ?
		map_textured(data->map_x, data->map_y) : 0;
	if (data->side == 0)
		data->wall_x = data->ray_pos_y + data->perp_wall_dis * data->ray_dir_y;
	else
		data->wall_x = data->ray_pos_x + data->perp_wall_dis * data->ray_dir_x;
	data->wall_x -= floor((data->wall_x));
	data->t_xx = (int)(data->wall_x * (double)data->tex[data->tex_n].width);
	if (data->side == 0 && data->ray_dir_x > 0)
		data->t_xx = data->tex[data->tex_n].width - data->t_xx - 1;
	if (data->side == 1 && data->ray_dir_y < 0)
		data->t_xx = data->tex[data->tex_n].width - data->t_xx - 1;
}
