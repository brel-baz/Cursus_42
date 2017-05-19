/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brel-baz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/13 02:16:19 by brel-baz          #+#    #+#             */
/*   Updated: 2017/05/13 02:16:22 by brel-baz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	perspective(t_draw *dw)
{
	dw->i = 0;
	dw->cz = 1;
	while (dw->i < dw->length)
	{
		dw->j = 0;
		while (dw->j < dw->width)
		{
			dw->tx = dw->tab2[dw->i][dw->j].y;
			dw->ty = dw->tab2[dw->i][dw->j].x;
			dw->tz = dw->tab2[dw->i][dw->j].z;
			dw->tab3[dw->i][dw->j].x = dw->tx * 2 - dw->ty * 2;
			dw->tab3[dw->i][dw->j].y = dw->tx + dw->ty - dw->tz * dw->cz;
			dw->tab3[dw->i][dw->j].x *= dw->zoom;
			dw->tab3[dw->i][dw->j].y *= dw->zoom;
			dw->j++;
		}
		dw->i++;
	}
}

void	get_point(t_draw *dw)
{
	dw->zoom = 5;
	dw->trr = WIDTH / 2;
	dw->trl = LENGTH / 2;
	dw->e2 = 0.0;
	dw->length = get_length(dw->str);
	dw->width = get_width(dw->str, 0, 0, 0);
	dw->tab2 = create_tab(dw->length, dw->width, dw->str, dw);
	dw->tab3 = create_tab(dw->length, dw->width, dw->str, dw);
	color(dw);
}

void	draw_win(t_draw *dw)
{
	dw->i = -1;
	while (++dw->i < dw->length - 1)
	{
		dw->j = -1;
		while (++dw->j < dw->width - 1)
		{
			line((t_point){dw->tab3[dw->i][dw->j].x, dw->tab3[dw->i][dw->j].y,
			dw->tab3[dw->i][dw->j].z},
			(t_point){dw->tab3[dw->i + 1][dw->j].x,
			dw->tab3[dw->i + 1][dw->j].y, dw->tab3[dw->i][dw->j].z}, dw);
			line((t_point){dw->tab3[dw->i][dw->j].x, dw->tab3[dw->i][dw->j].y,
			dw->tab3[dw->i][dw->j].z},
			(t_point){dw->tab3[dw->i][dw->j + 1].x,
			dw->tab3[dw->i][dw->j + 1].y, dw->tab3[dw->i][dw->j].z}, dw);
		}
	}
	line((t_point){dw->tab3[dw->i][0].x, dw->tab3[dw->i][0].y,
	dw->tab3[dw->i][dw->j].z},
	(t_point){dw->tab3[dw->i][dw->j].x, dw->tab3[dw->i][dw->j].y,
	dw->tab3[dw->i][dw->j].z}, dw);
	line((t_point){dw->tab3[0][dw->j].x, dw->tab3[0][dw->j].y,
	dw->tab3[dw->i][dw->j].z},
	(t_point){dw->tab3[dw->i][dw->j].x, dw->tab3[dw->i][dw->j].y,
	dw->tab3[dw->i][dw->j].z}, dw);
}

void	set_image(t_draw *dw)
{
	perspective(dw);
	dw->img = mlx_new_image(dw->mlx, 1300, 1300);
	dw->data = mlx_get_data_addr(dw->img, &dw->bpp,
	&dw->size_line, &dw->endian);
	mlx_clear_window(dw->mlx, dw->win);
	dw->color = dw->tab_color[dw->k];
	draw_win(dw);
	mlx_put_image_to_window(dw->mlx, dw->win, dw->img, 0, 0);
	mlx_string_put(dw->mlx, dw->win, 10, 1170, dw->color, "PRESS ESC: QUIT");
	mlx_string_put(dw->mlx, dw->win, 10, 1190, dw->color,
	"PRESS C: CHANGE COLOR");
	mlx_string_put(dw->mlx, dw->win, 10, 1210, dw->color, "PRESS R: RESET");
	mlx_string_put(dw->mlx, dw->win, 10, 1230, dw->color,
	"PRESS +: ZOOM FRONT");
	mlx_string_put(dw->mlx, dw->win, 10, 1250, dw->color, "PRESS -: ZOOM BACK");
	mlx_string_put(dw->mlx, dw->win, 10, 1270, dw->color,
	"PRESS ARROW KEYS: MOVE");
	mlx_destroy_image(dw->mlx, dw->img);
}
