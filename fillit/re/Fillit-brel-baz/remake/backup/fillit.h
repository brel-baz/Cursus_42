/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jreszka <jreszka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/05 14:25:45 by jreszka           #+#    #+#             */
/*   Updated: 2017/01/05 15:20:06 by jreszka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "libft.h"
# include <fcntl.h>
# include <stdio.h>

# define BUFF_SIZE 4096

int		ft_size_map(char *str);
int		ft_check_link(char *str);
char	**ft_tetris_table(char *str);
char	**ft_move_tetriminos(char **table, char *str);
char	**ft_convert_alpha(char **table, char *str);
char	**ft_map_generator(int size);
int		ft_check_high(char *str);
int		ft_check_left(char *str);
int		ft_check_solve(char *str, char **tab, int x, int y, int size);
int		ft_count_hash(char *str);
char	**ft_decalage(char **solve, char c, int size);
char	ft_get_char(char *str);
char	*ft_move_high(char*str);
char	*ft_move_left(char*str);
char	*ft_parse_tetri(char *str);
int 	ft_solve(char **tab, char *str, int x, int y, int size);
int		ft_check_bottom(char **solve, char c, int size);
int		ft_check_right(char **solve, char c, int size);
char	**ft_move_bottom(char **solve, char c, int size);
char	**ft_move_right(char **solve, char c, int size);

#endif