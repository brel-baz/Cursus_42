/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brel-baz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/05 19:16:52 by brel-baz          #+#    #+#             */
/*   Updated: 2017/06/05 20:09:17 by brel-baz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void		err_exit(char *str, t_data data)
{
	(void)data.mlx;
	ft_putendl(str);
	exit(1);
}

void		usage(void)
{
	ft_putendl("usage : ./wolf3d [name]");
	ft_putendl("\nname :");
	ft_putendl("1. untextured or 1");
	ft_putendl("2. textured or 2");
	ft_putendl("\nMOVE :");
	ft_putendl("1. Right      Key right");
	ft_putendl("2. Left       Key left");
	ft_putendl("3. Forward    Key up");
	ft_putendl("4. Backward   Key down");
	exit(1);
}
