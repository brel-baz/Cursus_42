/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_untextured_textured.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brel-baz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/05 19:12:57 by brel-baz          #+#    #+#             */
/*   Updated: 2017/06/05 19:23:27 by brel-baz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		hook_after_val(t_data *data, int key)
{
	if (key == MENU_HIDE && data->val == 1)
		after_val(data);
	else if (key == MENU_HIDE && data->val == 2)
		after_val(data);
	else
		;
	return (0);
}

void	chose_hook(t_data *data, int key)
{
	if (data->val == 1 && key >= 0)
	{
		key_hook_r_left_right(key, data);
		key_hook_left_right(key, data);
		key_hook_stop_hit(key, data);
	}
	else if (data->val == 2 && key >= 0)
	{
		key_hook_r_left_right_tex(key, data);
		key_hook_left_right_tex(key, data);
		key_hook_stop_hit_tex(key, data);
	}
	else
		;
}

int		exit_program(int key, t_data *data)
{
	ft_putendl("Exit Program");
	exit(1);
	return (0);
}

int		key_hook(int key, t_data *data)
{
	chose_hook(data, key);
	if (key == ESC)
		err_exit("Exit Program", *data);
	if (data->val == 1 && key >= 0)
	{
		set_image_untextured(data);
		mlx_string_put(data->mlx, data->win, 20, 10, 0xff0000, "exit = esc");
		mlx_string_put(data->mlx, data->win, 20, 30, 0xff0000, "help = H");
		hook_after_val(data, key);
	}
	else if (data->val == 2 && key >= 0)
	{
		set_texture(data);
		mlx_string_put(data->mlx, data->win, 20, 10, 0xff0000, "exit = esc");
		mlx_string_put(data->mlx, data->win, 20, 30, 0xff0000, "help = H");
		hook_after_val(data, key);
	}
	return (0);
}
