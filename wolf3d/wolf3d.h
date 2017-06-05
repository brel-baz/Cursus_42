/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brel-baz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/05 19:18:15 by brel-baz          #+#    #+#             */
/*   Updated: 2017/06/05 19:40:22 by brel-baz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H
# include "libft/libft.h"
# include "mlx/mlx.h"
# include <math.h>
# define WIDTH 1256
# define HEIGHT 1000
# define UP 126
# define DOWN 125
# define RIGHT 2
# define LEFT 0
# define ESC 53
# define R_RIGHT 124
# define R_LEFT 123
# define TEX_W 64
# define TEX_H 64
# define MENU_HIDE 4

typedef struct		s_tex
{
	void			*img;
	char			*pixel;
	int				width;
	int				height;
	int				bpp;
	int				size_line;
	int				endian;
}					t_tex;

typedef struct		s_data
{
	void			*mlx;
	void			*win;
	void			*img;
	char			*pixel;
	int				x;
	int				y;
	double			pos_x;
	double			pos_y;
	double			dir_x;
	double			dir_y;
	double			plane_x;
	double			plane_y;
	double			ray_pos_x;
	double			ray_pos_y;
	double			ray_dir_x;
	double			ray_dir_y;
	double			cam_x;
	int				map_x;
	int				map_y;
	double			delta_dis_x;
	double			delta_dis_y;
	int				step_x;
	int				step_y;
	double			side_dis_x;
	double			side_dis_y;
	int				hit;
	int				side;
	double			perp_wall_dis;
	double			line_height;
	int				draw_start;
	int				draw_end;
	int				size_line;
	int				bpp;
	int				endian;
	int				color;
	double			rot;
	double			speed;
	double			t_d;
	double			t_p;
	t_tex			tex[12];
	int				tex_n;
	double			wall_x;
	int				t_xx;
	int				t_xy;
	int				val;
}					t_data;

int					exit_program(int key, t_data *data);
void				calc_height_line(t_data *data);
void				calc_height_line_tex(t_data *data);
void				textured_calc_tex(t_data *data);
void				draw_ceiling_floor(t_data *data, int x);
int					get_texture_color(t_data *data);
void				after_val(t_data *data);
int					hook_after_val(t_data *data, int key);
int					key_hook_r_left_right_tex(int key, t_data *data);
int					key_hook_left_right_tex(int key, t_data *data);
int					key_hook_stop_hit_tex(int key, t_data *data);
int					key_hook_left_right(int key, t_data *data);
int					key_hook_r_left_right(int key, t_data *data);
int					key_hook_stop_hit(int key, t_data *data);
void				textured(t_data *data);
void				set_texture(t_data *data);
void				init_2(t_data *data);
void				init_xpm(t_data *data);
int					map_textured(int x, int y);
int					key_hook(int key, t_data *data);
void				set_pixel(int x, int y, int color, t_data *data);
int					map_untextured(int x, int y);
void				untextured(t_data *data);
void				set_image_untextured(t_data *data);
void				print_map(t_data *data, int x);
void				ray_pos(t_data *data, int x);
void				init_1(t_data *data);
void				err_exit(char *str, t_data data);
void				usage(void);

#endif
