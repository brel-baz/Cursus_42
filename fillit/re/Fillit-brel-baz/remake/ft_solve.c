/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brel-baz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/29 04:07:47 by brel-baz          #+#    #+#             */
/*   Updated: 2016/12/29 09:06:26 by brel-baz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int		ft_size_map(char *str);
char	**ft_map_generator(int size);
int		ft_check_solve(char *str, char **tab);

char	**ft_solve(char **tab, char *str)
{
	char **solve;
	int i;
	int j;

	solve = ft_map_generator(ft_size_map(str));
	j = 0;
	while (j < ft_size_map(str))
	{
		i = 0;
		if (ft_check_solve(tab[j], solve) == 4)
		{
			while (tab[j][i])
			{
				solve[i / 5][i % 5] = tab[j][i];
				i++;
			}
		}
		j++;
	}
	j = 0;
	while (j < ft_size_map(str))
	{
		printf("%s", solve[j]);
		j++;
	}
	return (solve);
}
