/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brel-baz <brel-baz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/29 04:07:47 by brel-baz          #+#    #+#             */
/*   Updated: 2017/01/22 08:49:12 by brel-baz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include "fillit.h"


int		ft_solve(char **tab, char *str, int x, int y, int size)
{
	int i;
	int ligne = -1;
	int k = 0;
	int check_placed = 0;
	char **solve = ft_map_generator(size);
	int tetri_nb =ft_count_hash(str);
	int flag = 0;
	int l = 0;
	char *tmp;
	int j = 0;
	char **save = tab;
	char **save2 = tab;

	while (++ligne < tetri_nb)
	{
		i = - 1;
		y = 0;
		x = 0;
		if (flag == 1)
		{
			flag = 0;
			ligne = 0;
		}
		
		while (ft_check_solve(save[ligne], solve, x, y, size) != 4)
		{ 
			y++;
			if (solve[x][y] == '\0')
			{
				x++;
				y = 0 ;
			}
			if (ft_check_solve(save[ligne], solve, x, y, size) == - 1)
			{
				ft_putnbr(j);
				ft_putchar('\n');
				if (j + 1 == tetri_nb)
				{
					if (l < tetri_nb)
						l++;
					j = l;
					free(save);
					save = save2;
				}
				tmp = save[j];
				save[j] = save[j + 1];
				save[j + 1] = tmp;
				flag = 1;
				j++;
				// ft_putnbr(l);
				// ft_putchar('\n');
				// ft_putnbr(j);
				// ft_putchar('\n');
				// if (j == tetri_nb)
				// 	return (0);
				k = 0;
				check_placed = 0;
				free(solve);
				solve = ft_map_generator(size);
				k = 0;
				ligne = 0;
				while (k < size)
				{
					printf("%s\n", solve[k]);
					k++;
				}
				ft_putchar('\n');
				break;
			}
		}
		if (ft_check_solve(save[ligne], solve, x, y, size) == 4 && flag == 0)
		{
			while (save[ligne][++i])
			{
				if (ft_isalpha(save[ligne][i]) == 1)
					solve[i / 5 + x][i % 5 + y] = save[ligne][i];
			}
			check_placed++;
		}
		k = 0;
		while (k < size)
		{
			printf("%s\n", solve[k]);
			k++;
		}
		ft_putchar('\n');
	}
	if (check_placed != tetri_nb)
		return (0);
	k = 0;
	while (k < size)
	{
		printf("%s\n", solve[k]);
		k++;
	}
	ft_putchar('\n');
	return (1);
}