/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brel-baz <brel-baz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/29 04:07:47 by brel-baz          #+#    #+#             */
/*   Updated: 2017/01/10 09:18:21 by brel-baz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_solve(char **tab, char *str, int x, int y, int size)
{
	char **solve;
	int i;
	int ligne;
	int k;
	int tetri_nb;
	//int check_placed = 0;
	//int r = 0;
	int s = 1;
	char *tmp;
	//int s = 1;

	solve = ft_map_generator(size);
	ligne = - 1;
	tetri_nb = ft_count_hash(str);
	while (++ligne < tetri_nb)
	{
		i = - 1;
		y = 0;
		x = 0;
		while (ft_check_solve(tab[ligne], solve, x, y, size) != 4)
		{ 
			y++;
			if (solve[x][y] == '\0')
			{
				x++;
				y = 0 ;
			}
			if (ft_check_solve(tab[ligne], solve, x, y, size) == - 1 && ligne > 0)
			{
				free(solve);
				solve = ft_map_generator(size);
				tmp = tab[0];
				tab[0] = tab[s];
				tab[s] = tmp;
				s++;
				ligne = 0;
				break;
			}
		}

		if (ft_check_solve(tab[ligne], solve, x, y, size) == 4)
		{
			while (tab[ligne][++i])
			{
				if (ft_isalpha(tab[ligne][i]) == 1)
					solve[i / 5 + x][i % 5 + y] = tab[ligne][i];
			
			}
		}
	}
	printf("%s\n", "fin\n");
	k = 0;
	while (k < size)
	{
		printf("%s\n", solve[k]);
		k++;
	}
	ft_putchar('\n');
	return (1);
}
