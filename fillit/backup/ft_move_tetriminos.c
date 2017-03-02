/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_tetriminos.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brel-baz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 18:13:07 by brel-baz          #+#    #+#             */
/*   Updated: 2017/01/01 17:51:23 by brel-baz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	**ft_tetris_table(char *str);
int		ft_check_high(char *str);
int		ft_check_left(char *str);
char	*ft_move_high(char *str);
char	*ft_move_left(char *str);
int		ft_count_hash(char *str);

char	**ft_move_tetriminos(char **table, char *str)
{
	int i;
	int j;

	j = 0;
	while (j < ft_count_hash(str))
	{
		i = 0;
		while (i < 4)
		{
			if (ft_check_left(table[j]) == 4)
				ft_move_left(table[j]);
			if (ft_check_high(table[j]) == 4)
				ft_move_high(table[j]);
			i++;
		}
//		printf("%s\n", table[j]);
		j++;
	}
	return (table);
}
