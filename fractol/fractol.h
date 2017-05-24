/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brel-baz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/18 23:23:11 by brel-baz          #+#    #+#             */
/*   Updated: 2017/05/18 23:26:08 by brel-baz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# include "libft/libft.h"
# include <math.h>
# include "mlx/mlx.h"
# include <sys/types.h>
# include <fcntl.h>
# define WIDTH 500
# define LENGTH 500

typedef		struct 	s_dw
{
	int 			x;
	int 			y;
	double			x1;
	double			y1;
	double			x2;
	double			y2;
	int				image_x;
	int				image_y;
	int 			color;
	double			zoom_x;
	double			zoom_y;
	double 			zoom;
	int 			endian;
	int				size_line;
	int 			bpp;
	double			c_r;
	double			c_i;
	double			z_r;
	double			z_i;
	double			i;
	double			tmp;
	char			*data;
	void			*mlx;
	void			*win;
	void			*img;
	int				i_max;
}					t_dw;

#endif
