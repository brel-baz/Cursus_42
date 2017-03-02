/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tetris_table.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brel-baz <brel-baz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 22:42:31 by brel-baz          #+#    #+#             */
/*   Updated: 2017/01/20 19:24:29 by brel-baz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**ft_tetris_table(char *str)
{
	int		i;
	int		j;
	int		k;
	char	**tetris_table;

	i = 0;
	j = 0;
	k = 0;
	tetris_table = (char**)malloc(sizeof(char*) * ft_count_hash(str));
	while (j < ft_count_hash(str))
	{
		tetris_table[j] = (char*)malloc(sizeof(char) * 20);
		k = 0;
		while (k < 20)
		{
			tetris_table[j][k] = str[i];
			k++;
			i++;
		}
		tetris_table[j][k] = '\0';
		j++;
		i++;
	}
	return (tetris_table);
}
