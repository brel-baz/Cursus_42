/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brel-baz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/18 23:23:11 by brel-baz          #+#    #+#             */
/*   Updated: 2017/05/26 10:35:37 by brel-baz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include "libft/libft.h"
# include <math.h>
# include <mlx.h>
# include <sys/types.h>
# include <fcntl.h>
# define WIDTH 400
# define LENGTH 400
# define ESC 53
# define RIGHT 124
# define LEFT 123
# define UP 126
# define DOWN 125
# define RESET 15
# define COLOR 8
# define IN 5
# define OUT 4
# define SPACE 49
# define FRACTALE 3

typedef struct		s_dw
{
	int				fract;
	int				x;
	int				y;
	double			x1;
	double			y1;
	double			x2;
	double			y2;
	int				image_x;
	int				image_y;
	int				color;
	double			zoom_x;
	double			zoom_y;
	double			zoom;
	int				endian;
	int				size_line;
	int				bpp;
	int				tab_color[11];
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
	int				k;
}					t_dw;

void				set_image(t_dw *dw);
void				pixel_put(int x, int y, int color, t_dw *dw);
void				mandelbrot_init(t_dw *dw);
void				mandelbrot_init2(t_dw *dw);
void				mandelbrot(t_dw *dw);
void				julia_init(t_dw *dw);
void				julia_init2(t_dw *dw);
void				julia(t_dw *dw);
void				douady_init(t_dw *dw);
void				douady_init2(t_dw *dw);
void				douady(t_dw *dw);
void				siegel_init(t_dw *dw);
void				siegel_init2(t_dw *dw);
void				siegel(t_dw *dw);
void				burningship_init(t_dw *dw);
void				burningship_init2(t_dw *dw);
void				burningship(t_dw *dw);
void				pixel_put(int x, int y, int color, t_dw *dw);
void				display_user_guide(void);
void				fractal(t_dw *dw);
void				fractal_init(t_dw *dw);
int					key_hook(int key, t_dw *dw);
int					mouse_zoom(int key, int x, int y, t_dw *dw);
int					mouse_change(int x, int y, t_dw *dw);

#endif
