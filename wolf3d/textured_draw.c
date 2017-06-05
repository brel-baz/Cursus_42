/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textured_draw.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brel-baz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/05 19:14:29 by brel-baz          #+#    #+#             */
/*   Updated: 2017/06/05 20:20:05 by brel-baz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void		load_xpm(t_data *data)
{
	data->tex[0].img = mlx_xpm_file_to_image(data->mlx, "pics/sky.xpm",
			&data->tex[0].width, &data->tex[0].height);
	data->tex[1].img = mlx_xpm_file_to_image(data->mlx, "pics/bstone.xpm",
			&data->tex[1].width, &data->tex[1].height);
	data->tex[2].img = mlx_xpm_file_to_image(data->mlx, "pics/ceil.xpm",
			&data->tex[2].width, &data->tex[2].height);
	data->tex[3].img = mlx_xpm_file_to_image(data->mlx, "pics/rbrick.xpm",
			&data->tex[3].width, &data->tex[3].height);
	data->tex[4].img = mlx_xpm_file_to_image(data->mlx, "pics/eagle.xpm",
			&data->tex[4].width, &data->tex[4].height);
	data->tex[5].img = mlx_xpm_file_to_image(data->mlx, "pics/wood.xpm",
			&data->tex[5].width, &data->tex[5].height);
	data->tex[6].img = mlx_xpm_file_to_image(data->mlx, "pics/cstone.xpm",
			&data->tex[6].width, &data->tex[6].height);
	data->tex[7].img = mlx_xpm_file_to_image(data->mlx, "pics/nazi.xpm",
			&data->tex[7].width, &data->tex[7].height);
	data->tex[8].img = mlx_xpm_file_to_image(data->mlx, "pics/egold.xpm",
			&data->tex[8].width, &data->tex[8].height);
	data->tex[9].img = mlx_xpm_file_to_image(data->mlx, "pics/bwall.xpm",
			&data->tex[9].width, &data->tex[9].height);
	data->tex[10].img = mlx_xpm_file_to_image(data->mlx, "pics/brstone.xpm",
			&data->tex[10].width, &data->tex[10].height);
}

void		init_xpm(t_data *data)
{
	int		i;

	load_xpm(data);
	i = -1;
	while (++i < 11)
	{
		data->tex[i].pixel = mlx_get_data_addr(data->tex[i].img,
				&data->tex[i].bpp, &data->tex[i].size_line,
				&data->tex[i].endian);
	}
}

int			get_texture_color(t_data *data)
{
	int		index_text;
	int		ptr;

	index_text = data->t_xy * data->tex[data->tex_n].size_line + data->t_xx *
		data->tex[data->tex_n].bpp / 8;
	ptr = *((int *)&data->tex[data->tex_n].pixel[index_text]);
	return (ptr);
}

void		set_texture(t_data *data)
{
	data->img = mlx_new_image(data->mlx, (int)WIDTH, (int)HEIGHT);
	data->pixel = mlx_get_data_addr(data->img, &data->bpp, &data->size_line,
			&data->endian);
	textured(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
}
