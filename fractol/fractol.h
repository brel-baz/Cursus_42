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
# define ESC 53
# define ZOOM_UP 69
# define ZOOM_LESS 78
# define COLOR 8

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
	int 			tab_color[11];
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
	int 			k;
}					t_dw;

void	mandelbrot_init(t_dw *dw);
void	mandelbrot_init2(t_dw *dw);
void	mandelbrot(t_dw *dw);
void	julia_init(t_dw *dw);
void	julia_init2(t_dw *dw);
void	julia(t_dw *dw);
void	buddhabrot_init(t_dw *dw);
void	buddhabrot_init2(t_dw *dw);
void	buddhabrot(t_dw *dw);
void	douady_init(t_dw *dw);
void	douady_init2(t_dw *dw);
void	douady(t_dw *dw);
void	siegel_init(t_dw *dw);
void	siegel_init2(t_dw *dw);
void	siegel(t_dw *dw);
void	burningship_init(t_dw *dw);
void	burningship_init2(t_dw *dw);
void	burningship(t_dw *dw);
void	pixel_put(int x, int y, int color, t_dw *dw);
#endif
