/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tetris_table.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brel-baz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 22:42:31 by brel-baz          #+#    #+#             */
/*   Updated: 2016/12/13 18:46:09 by brel-baz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_size_map(char *str);

char	**ft_tetris_table(char *str)
{
	int		i;
	int		j;
	int		k;
	char	**tetris_table;

	i = 0;
	j = 0;
	k = 0;
	tetris_table = (char**)malloc(sizeof(char*) * ft_size_map(str));
	while (j < ft_size_map(str))
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
