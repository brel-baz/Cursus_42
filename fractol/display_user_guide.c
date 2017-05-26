/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_user_guide.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brel-baz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/26 07:48:10 by brel-baz          #+#    #+#             */
/*   Updated: 2017/05/26 10:01:46 by brel-baz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	display_user_guide(void)
{
	ft_putstr_fd("Choose a fractal.\n", 2);
	ft_putstr_fd("1 : Julia.\n", 2);
	ft_putstr_fd("2 : Mandelbrot.\n", 2);
	ft_putstr_fd("3 : Burning Ship.\n", 2);
	ft_putstr_fd("4 : Siegel.\n", 2);
	ft_putstr_fd("5 : Douady.\n", 2);
	exit(-1);
}
