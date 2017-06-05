/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   untextured_next.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brel-baz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/05 19:16:35 by brel-baz          #+#    #+#             */
/*   Updated: 2017/06/05 19:25:14 by brel-baz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void		calc_height_line(t_data *data)
{
	data->perp_wall_dis = (data->side == 0) ? (data->map_x - data->ray_pos_x +
			(1 - data->step_x) / 2) / data->ray_dir_x : (data->map_y -
				data->ray_pos_y + (1 - data->step_y) / 2) / data->ray_dir_y;
	data->line_height = (int)(HEIGHT / data->perp_wall_dis);
	data->draw_start = -(data->line_height) / 2 + HEIGHT / 2;
	if (data->draw_start < 0)
		data->draw_start = 0;
	data->draw_end = HEIGHT / 2 + data->line_height / 2;
	if (data->draw_start >= HEIGHT)
		data->draw_end = HEIGHT - 1;
}
