/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brel-baz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/05 19:13:20 by brel-baz          #+#    #+#             */
/*   Updated: 2017/06/05 19:23:38 by brel-baz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void		init_1(t_data *data)
{
	data->pos_x = 11.5;
	data->pos_y = 4.5;
	data->dir_x = -1;
	data->dir_y = 0;
	data->plane_x = 0;
	data->plane_y = 0.66;
	data->hit = 0;
	data->rot = M_PI / (double)25;
	data->speed = 0.1;
}

void		init_2(t_data *data)
{
	init_xpm(data);
	data->pos_x = 4.5;
	data->pos_y = 3.5;
	data->dir_x = -1;
	data->dir_y = 0;
	data->plane_x = 0;
	data->plane_y = 0.66;
	data->hit = 0;
	data->rot = M_PI / (double)25;
	data->speed = 0.1;
}

void		after_val(t_data *data)
{
	mlx_string_put(data->mlx, data->win, 20, 780, 0x007000, "GamePlay");
	mlx_string_put(data->mlx, data->win, 20, 820, 0xff0000, "Move :");
	mlx_string_put(data->mlx, data->win, 20, 840, 0x00FF00, "RIGHT = D");
	mlx_string_put(data->mlx, data->win, 20, 860, 0x00FF00, "LEFT  = A");
	mlx_string_put(data->mlx, data->win, 20, 880, 0x00FF00, "FRONT = W");
	mlx_string_put(data->mlx, data->win, 20, 900, 0x00FF00, "BACK  = S");
	mlx_string_put(data->mlx, data->win, 20, 920, 0x00FF00,
			"ROTATE RIGHT = E");
	mlx_string_put(data->mlx, data->win, 20, 940, 0x00FF00,
			"ROTATE LEFT  = Q");
}
