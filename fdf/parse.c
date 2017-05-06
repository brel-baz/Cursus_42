/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brel-baz <brel-baz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/03 02:05:31 by brel-baz          #+#    #+#             */
/*   Updated: 2017/04/18 00:23:00 by brel-baz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	perspective(t_draw *dw)
{
	dw->tab3 = dw->tab2;
	dw->i = 0;
	dw->cz = 1;
	while (dw->i < dw->length)
	{
		dw->j = 0;
		while (dw->j < dw->width)
		{
			dw->tx = dw->tab3[dw->i][dw->j].y;
			dw->ty = dw->tab3[dw->i][dw->j].x;
			dw->tab3[dw->i][dw->j].x = dw->tx * 2 - dw->ty * 2;
			dw->tab3[dw->i][dw->j].y = dw->tx + dw->ty - dw->tab3[dw->i][dw->j].z * dw->cz;
			dw->tab3[dw->i][dw->j].x *= dw->zoom;
			dw->tab3[dw->i][dw->j].y *= dw->zoom;
			// dw->tab3[dw->i][dw->j].x += dw->trr;
			// dw->tab3[dw->i][dw->j].y += dw->trl;
			dw->j++;
		}
		dw->i++;
	}
}

void	get_point(t_draw *dw)
{
	dw->zoom = 2;
	dw->trr = 300;
	dw->trl = 300;
	dw->length = get_length(dw->str);
	dw->width = get_width(dw->str, 0, 0, 0);
	dw->tab2 = create_tab(dw->length, dw->width, dw->str, dw);
}

void	draw_win(t_draw *dw)
{
	dw->i = 0;
	while (dw->i < dw->length - 1)
	{
		dw->j = 0;
		while (dw->j < dw->width - 1)
		{
			line((t_point){dw->tab3[dw->i][dw->j].x, dw->tab3[dw->i][dw->j].y}, (t_point){dw->tab3[dw->i + 1][dw->j].x, dw->tab3[dw->i + 1][dw->j].y}, dw);
			line((t_point){dw->tab3[dw->i][dw->j].x, dw->tab3[dw->i][dw->j].y}, (t_point){dw->tab3[dw->i][dw->j + 1].x, dw->tab3[dw->i][dw->j + 1].y}, dw);
			dw->j++;
		}
		dw->i++;
	}
	line((t_point){dw->tab3[dw->i][0].x, dw->tab3[dw->i][0].y}, (t_point){dw->tab3[dw->i][dw->j].x, dw->tab3[dw->i][dw->j].y }, dw);
	line((t_point){dw->tab3[0][dw->j].x, dw->tab3[0][dw->j].y}, (t_point){dw->tab3[dw->i][dw->j].x, dw->tab3[dw->i][dw->j].y }, dw);
}

void	set_image(t_draw *dw)
{
	dw->img = mlx_new_image(dw->mlx, 1300, 1300);
	dw->data = mlx_get_data_addr(dw->img, &dw->bpp, &dw->size_line, &dw->endian);
	mlx_clear_window(dw->mlx, dw->win);
	draw_win(dw);
	mlx_put_image_to_window(dw->mlx, dw->win, dw->img, 0, 0);
	mlx_destroy_image(dw->mlx, dw->img);
	// mlx_clear_window(dw->mlx, dw->win);
}
int 	key_hook(int key, t_draw *dw)
{
	if (key == ZOOM_UP)
		zoom_up(dw);
	if (key == ZOOM_LESS)
		zoom_less(dw);
	if (key == TR_RIGHT)
		tr_right(dw);
	if (key == TR_LEFT)
		tr_left(dw);
	if (key == ESC)
		exit(1);
	set_image(dw);
	return (0);
}

int 	main(int ac, char **av)
{
	t_draw *dw;
	dw = (t_draw*)malloc(sizeof(t_draw));
	t_point point;
	dw->str = av[1];
	dw->mlx = mlx_init();
	dw->win = mlx_new_window(dw->mlx, 1300, 1300, "FDF");
	get_point(dw);
	perspective(dw);
	set_image(dw);
	mlx_hook(dw->win, 2, 3, key_hook, dw);
	mlx_loop(dw->mlx);
	return (0);
}
