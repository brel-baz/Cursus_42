/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brel-baz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/26 09:40:22 by brel-baz          #+#    #+#             */
/*   Updated: 2017/05/26 09:40:26 by brel-baz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	fractal(t_dw *dw)
{
	if (dw->fract == 1)
		julia(dw);
	else if (dw->fract == 2)
		mandelbrot(dw);
	else if (dw->fract == 3)
		burningship(dw);
	else if (dw->fract == 4)
		siegel(dw);
	else if (dw->fract == 5)
		douady(dw);
}

void	fractal_init(t_dw *dw)
{
	if (dw->fract == 1)
		julia_init(dw);
	else if (dw->fract == 2)
		mandelbrot_init(dw);
	else if (dw->fract == 3)
		burningship_init(dw);
	else if (dw->fract == 4)
		siegel_init(dw);
	else if (dw->fract == 5)
		douady_init(dw);
}
