/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brel-baz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/18 23:22:20 by brel-baz          #+#    #+#             */
/*   Updated: 2017/05/26 09:52:27 by brel-baz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	pixel_put(int x, int y, int color, t_dw *dw)
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

void	set_image(t_dw *dw)
{
	dw->img = mlx_new_image(dw->mlx, WIDTH, LENGTH);
	dw->data = mlx_get_data_addr(dw->img, &dw->bpp,
	&dw->size_line, &dw->endian);
	fractal(dw);
	mlx_clear_window(dw->mlx, dw->win);
	mlx_put_image_to_window(dw->mlx, dw->win, dw->img, 0, 0);
	mlx_string_put(dw->mlx, dw->win, 1, 270, 0xFF00D5, "PRESS ESC: QUIT");
	mlx_string_put(dw->mlx, dw->win, 1, 290, 0xFF00D5,
	"PRESS C: CHANGE COLOR");
	mlx_string_put(dw->mlx, dw->win, 1, 310, 0xFF00D5, "PRESS R: RESET");
	mlx_string_put(dw->mlx, dw->win, 1, 330, 0xFF00D5,
		"USE SCROLL WHEEL: ZOOM");
	mlx_string_put(dw->mlx, dw->win, 1, 350, 0xFF00D5,
	"PRESS ARROW KEYS: MOVE");
	mlx_string_put(dw->mlx, dw->win, 1, 370, 0xFF00D5,
		"PRESS F: CHANGE FRACTAL");
	mlx_destroy_image(dw->mlx, dw->img);
}

int		main(int ac, char **av)
{
	t_dw *dw;

	dw = (t_dw*)malloc(sizeof(t_dw));
	if (ac == 2)
	{
		if (ft_strcmp(av[1], "1") == 0 || ft_strcmp(av[1], "2") == 0 ||
			ft_strcmp(av[1], "3") == 0 || ft_strcmp(av[1], "4") == 0 ||
			ft_strcmp(av[1], "5") == 0)
			dw->fract = ft_atoi(av[1]);
		else
			display_user_guide();
		fractal_init(dw);
		dw->mlx = mlx_init();
		dw->win = mlx_new_window(dw->mlx, WIDTH, LENGTH, "Fractol");
		set_image(dw);
		mlx_hook(dw->win, 2, 3, key_hook, dw);
		mlx_hook(dw->win, 6, 7, mouse_change, dw);
		mlx_mouse_hook(dw->win, mouse_zoom, dw);
		mlx_loop(dw->mlx);
	}
	else
		display_user_guide();
	return (0);
}
