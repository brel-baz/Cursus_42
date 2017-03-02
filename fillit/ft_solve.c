/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brel-baz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/29 04:07:47 by brel-baz          #+#    #+#             */
/*   Updated: 2017/01/06 04:11:25 by brel-baz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int		ft_size_map(char *str);
int		ft_count_hash(char *str);
char	**ft_map_generator(int size);
int		ft_check_solve(char *str, char **tab, int x, int y, int size);

int		ft_solve(char **tab, char *str, int x, int y, int size)
{
	char **solve;
	int i;
	int j;
	int k;
//	int cs;

	solve = ft_map_generator(size);
	j = - 1;
	while (++j < ft_count_hash(str))
	{
		i = - 1;
		y = 0;
		x = 0;
		while (ft_check_solve(tab[j], solve, x, y, size) != 4)
		{
			y++;
			if (solve[x][y] == '\0')
			{
				x++;
				y = 0;
			}
			if (ft_check_solve(tab[j], solve, x, y, size) == - 1)
			{

			}
			else
			{
				free(solve);
				size++;
				solve = ft_map_generator(size);
				j = 0;
				x = 0;
				y = 0;
				break;
			}
		}
		if (ft_check_solve(tab[j], solve, x, y, size) == 4)
		{
			while (tab[j][++i])
			{
				if (ft_isalpha(tab[j][i]) == 1)
					solve[i / 5 + x][i % 5 + y] = tab[j][i];
			}
		}
	}

	k = 0;
	while (k < size)
	{
		printf("%s\n", solve[k]);
		k++;
	}
	return (1);
}
