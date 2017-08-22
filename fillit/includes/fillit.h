/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jreszka <jreszka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/06 10:47:23 by jreszka           #+#    #+#             */
/*   Updated: 2017/01/16 16:12:59 by jreszka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <fcntl.h>
# include "../libft/libft.h"

# define BUF_SIZE 4096
# define NORMAL_DOT_NB 12
# define NORMAL_HASH_NB 4
# define MIN_CHAR_NB 20
# define MAX_CHAR_NB 546

typedef struct		s_data
{
	int char_nb;
	int hash_nb;
	int dot_nb;
	int border_nl_nb;
	int between_nl_nb;
	int tetri_nb;
	int tetri_i;
	int hash_i;
	int neighbours_nb;
}					t_data;

typedef struct		s_point
{
	int x;
	int y;
}					t_point;

typedef struct		s_tet
{
	t_point			ref_min;
	t_point			ref_max;
	t_point			hash[4];
	t_point			pos;
	char			lettre;
	int				width;
	int				height;
	int				is_placed;
}					t_tet;

typedef struct		s_map
{
	int				size;
	char			**content;
	t_tet			*tets;
	int				table_i;
	int				tets_i;
	int				charac_i;
	int				hash_i;
	int				min_x;
	int				min_y;
	int				max_x;
	int				max_y;
	int				placed_tets_nb;
	t_point			pos;
}					t_map;

char				*get_buf(char *file_name);
t_data				parse(char *buf, t_data data);
int					num_are_valid(t_data data);
int					hash_neighbours_are_valid(char *buf, t_data data);
void				ft_print_2d_table(char **str);
int					ft_int_sqrt(int nb);
t_map				ft_init_map(t_map map, t_data data);
t_map				ft_build_tets(char **table, t_map map, t_data data);
t_map				ft_tets_ref_points(t_map map, t_data data);
t_map				ft_tets_chars(t_map map, t_data data);
int					can_place_tet(int i, t_map map, int pos_x, int pos_y);
void				place_tet(int i, t_map map, int pos_x, int pos_y);
int					can_move_tet_right(int i, t_map map);
int					can_move_tet_bottom(int i, t_map map);
int					can_displace_tetri(int i, t_map map);
int					first_tetri_can_be_displaced(t_map map);
t_map				init_tets_pos(t_map map, t_data data);
t_map				rm_tet(int i, t_map map);
int					is_placed_tet(int i, t_map map);
t_map				move_tet_pos(int i, t_map map);
t_map				try_place_all_tets(t_map map);
int					ft_solve(t_map map, t_data data);
t_map				make_map_bigger(t_map map);

#endif
