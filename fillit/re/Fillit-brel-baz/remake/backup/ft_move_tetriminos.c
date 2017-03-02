/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_tetriminos.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jreszka <jreszka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 18:13:07 by brel-baz          #+#    #+#             */
/*   Updated: 2017/01/05 14:18:09 by jreszka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

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
		j++;
	}
	return (table);
}
