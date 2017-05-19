/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brel-baz <brel-baz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/05 02:23:41 by brel-baz          #+#    #+#             */
/*   Updated: 2017/05/15 04:36:06 by brel-baz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "libft/libft.h"
# include <math.h>
# include <mlx.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# define ESC 53
# define ZOOM_UP 69
# define ZOOM_LESS 78
# define RIGHT 124
# define LEFT 123
# define UP 126
# define DOWN 125
# define WIDTH 1300
# define LENGTH 1300
# define RESET 15
# define COLOR 8

typedef struct		s_point
{
	double			x;
	double			y;
	double			z;
}					t_point;

typedef struct		s_draw
{
	t_point			**tab2;
	t_point			**tab3;
	double			dx;
	double			sx;
	double			dy;
	double			sy;
	double			err;
	double			e2;
	double			cz;
	double			tx;
	double			ty;
	double			tz;
	double			length;
	double			width;
	int				tab_color[11];
	int				color;
	int				zoom;
	int				zo;
	int				trr;
	int				trl;
	int				i;
	int				j;
	int				k;
	char			*str;
	char			**tab;
	int				bpp;
	int				size_line;
	int				endian;
	char			*data;
	void			*mlx;
	void			*win;
	void			*img;
}					t_draw;

int					check_line(char *str);
int					get_length(char *file);
int					get_width(char *file, int flag, int check, int x);
t_point				**create_tab(double x, double y, char *file, t_draw *dw);
void				line(t_point p0, t_point p1, t_draw *dw);
int					key_hook(int key, t_draw *dw);
void				perspective(t_draw *dw);
void				zoom_up(t_draw *dw);
void				zoom_less(t_draw *dw);
void				tr_right(t_draw *dw);
void				tr_left(t_draw *dw);
void				color(t_draw *dw);
void				get_point(t_draw *dw);
void				set_image(t_draw *dw);

#endif
